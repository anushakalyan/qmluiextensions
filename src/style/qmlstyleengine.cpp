/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Components project.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtCore/qstring.h>
#include <QtGui/qcolor.h>
#include <QTextStream>
#include <QHash>
#include <QLatin1String>
#include <QFont>
#include <QDir>
#include <QMetaObject>
#include <qobjectdefs.h>
#include <QFile>
#include <qmath.h>
#include <QDebug>

#include "qmlstyleengine.h"
#include "mdeclarativescreen_bridge.h"



// Parameters for magic unit value (RnD feature)
// -> See loadParameters documentation for details
static const qreal MID_POINT = 3.5;
static const qreal MID_VALUE = 3.2;
static const qreal RANGE = 1.0;
static const qreal ATAN_FACTOR = 1.5;

class QmlStyleEnginePrivate
{
public:
    QmlStyleEnginePrivate() {}

    enum ParameterType {
        ParameterType_Integer,
        ParameterType_Unit,
        ParameterType_Color
    };

    void init(const QString &styleName, const QString &colorSchemeName);
    bool updateLayoutParameters();
    bool updateColorParameters();
    void loadParameters(const QString &filePath, ParameterType type);
    void resolveFont();
    void _q_displayChanged();

protected:
    QmlStyleEngine *q_ptr;
private:
    QHash<QString, int> layoutParameters;
    QHash<QString, QColor> colorParameters;
    QHash<QString, QString> fontFamilyParameters;
    QString displayConfig;
    QString mStyleName;
    //QString mLayoutStyleDirectory;
    QString mLastUsedLayoutFile;
    //QString mColorSchemeDirectory;
    QString mColorScheme;
    QString mLastUsedColorFile;
    bool mUseDefaultFallBackParams;
    Q_DECLARE_PUBLIC(QmlStyleEngine)
};

void QmlStyleEnginePrivate::init(const QString &styleName, const QString &colorSchemeName)
{
    Q_Q(QmlStyleEngine);
    q->setPlatformStyle(styleName);
    q->setColorScheme(colorSchemeName);
    resolveFont();
}

bool QmlStyleEnginePrivate::updateColorParameters()
{
    QString paramsFile(":/params/"+mStyleName+"/colors/" + mColorScheme +".params");
    qDebug("first try with color%s",qPrintable(paramsFile));
    if (!QFile::exists(paramsFile)) {//if no current scheme exits check for default style color scheme
        qWarning("no %s color scheme settings found for current platform style",qPrintable(mColorScheme));
        paramsFile = ":/params/"+mStyleName+"/colors/default.params";
            qDebug("second try with color%s",qPrintable(paramsFile));
        if (!QFile::exists(paramsFile)) {//if no current defualt scheme exits fall back to default style color scheme
            qWarning("no default color scheme settings found for current style, using defualt colour scheme from default style.");
            mColorScheme = "default";
            paramsFile = ":/params/default/"+mColorScheme+".params";
                qDebug("third try with color%s",qPrintable(paramsFile));
        }
    }
    if (mLastUsedColorFile.compare(paramsFile)) {
        colorParameters.clear();
        mLastUsedColorFile = paramsFile;
        qDebug("using try with color%s",qPrintable(paramsFile));
        loadParameters(paramsFile, ParameterType_Color);
        return true;
    }
    return false;
}

bool QmlStyleEnginePrivate::updateLayoutParameters()
{
    MDeclarativeScreen *screen = MDeclarativeScreen::instance();
    QString longEdge = QString::number(qMax(screen->displayWidth(), screen->displayHeight()));
    QString shortEdge = QString::number(qMin(screen->displayWidth(), screen->displayHeight()));
    QString ppi = QString::number(qRound(screen->dpi() / 5.0) * 5); // round to closest 5
    QString newDisplayConfig = longEdge + QLatin1Char('_') + shortEdge + QLatin1Char('_') + ppi;
    if (displayConfig != newDisplayConfig) {
        ParameterType type = ParameterType_Integer;
        QString layoutFile(":/params/"+mStyleName+"/layouts/" + newDisplayConfig +".params");
            qDebug("first try with layout %s",qPrintable(layoutFile));
        if (!QFile::exists(layoutFile)) {
            type = ParameterType_Unit;
            qDebug("no specification found for current dispaly config, using fallback params");
            if (!mUseDefaultFallBackParams) {
                layoutFile = ":/params/"+mStyleName+"/layouts/fallback.params";
                qDebug("second try with layout%s",qPrintable(layoutFile));
                if (!QFile::exists(layoutFile)) {
                    qDebug("no fallback params found for current style, using default style fallback params");
                    mUseDefaultFallBackParams = true;
                }
            }
            if (mUseDefaultFallBackParams)
                layoutFile = QLatin1String(":/params/default/layouts/fallback.params");
        }
        if (mLastUsedLayoutFile.compare(layoutFile)) {
            layoutParameters.clear();
            qDebug("final try with layout%s",qPrintable(layoutFile));
            mLastUsedLayoutFile = layoutFile;
            loadParameters(layoutFile, type);
        }
        displayConfig = newDisplayConfig;
        return true;
    }
    return false;
}

void QmlStyleEnginePrivate::loadParameters(const QString &filePath, ParameterType type)
{
    qreal unit(0.0);
    if (type == ParameterType_Unit) {
        // Magic unit formula
        //
        // This is an RnD feature that makes it possible to scale the
        // components to any arbitrary screen resolution/dpi. There should
        // be device specific parameter files for all real device configuration
        // and this function should not be hit from real hardware.
        //
        // The arctan function calculates the "primary text height" in
        // millimeters and all the parameters are defined in "units"
        // that's a fourth of the "primary text height"
        //
        // The magic unit formula can be controlled with four parameters:
        // - MID_POINT: the inch size of the reference display
        // - MID_VALUE: "primary text height" in millimeters at MID_POINT
        // - RANGE: the range of "primary text height" in millimeters
        // - ATAN_FACTOR: controls the "steepness" of the arctan curve
        MDeclarativeScreen *screen = MDeclarativeScreen::instance();
        qreal inchSize = qSqrt(screen->height() * screen->height()
                               + screen->width() * screen->width()) / screen->dpi();
        qreal pthMm = MID_VALUE + RANGE * qAtan(ATAN_FACTOR * (inchSize - MID_POINT)) / M_PI;
        unit = 0.25 * pthMm * screen->dpi() / 25.4;
    }

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line.isEmpty() || line.startsWith(QLatin1Char('#')))
                continue;

            int colonId = line.indexOf(QLatin1Char(':'));
            if (colonId < 0)
                return;

            // QVariant value;
            QString valueStr = line.mid(colonId + 1).trimmed();
            if (type == ParameterType_Color) {
                // do implicit string-to-color conversion
                QColor color(valueStr);
                QString trimmedvalue = line.left(colonId).trimmed();
                qDebug()<<color;
                qDebug("value:%s",qPrintable(trimmedvalue));
                colorParameters.insert(trimmedvalue, color);
            } else {
                int intVal(-1);
                bool ok(false);
                if (type == ParameterType_Unit && valueStr.endsWith(QLatin1String("un"))) {
                    valueStr.chop(2);
                    qreal temp = valueStr.toFloat(&ok);
                    if (ok)
                        intVal = qRound(unit * temp);
                } else {
                    int temp = valueStr.toInt(&ok);
                    if (ok)
                        intVal = temp;
                }
                QString trimmedvalue = line.left(colonId).trimmed();
                qDebug()<<intVal;
                qDebug("value:%s",qPrintable(trimmedvalue));
                layoutParameters.insert(trimmedvalue, intVal);
            }
        }
        file.close();
    }
}

void QmlStyleEnginePrivate::resolveFont()
{
#ifdef Q_OS_SYMBIAN
    QString fontFamily = QFont().defaultFamily();
#else
    QString fontFamily = QLatin1String("Nokia Sans");
#endif
    fontFamilyParameters.insert(QLatin1String("font-family-regular"), fontFamily);
}

void QmlStyleEnginePrivate::_q_displayChanged()
{
    Q_Q(QmlStyleEngine);
    if (updateLayoutParameters())
        emit q->layoutParametersChanged();
}

QmlStyleEngine::QmlStyleEngine(const QString &styleName, const QString &colorSchemeName,QObject *parent)
    : QObject(parent),
      d_ptr(new QmlStyleEnginePrivate())
{
    Q_D(QmlStyleEngine);
    d->q_ptr = this;
    // Screen size can change on desktop (RnD feature)
    QObject::connect(MDeclarativeScreen::instance(), SIGNAL(displayChanged()), this, SLOT(_q_displayChanged()));
    d->init(styleName,colorSchemeName);
}

QmlStyleEngine::~QmlStyleEngine()
{
}

int QmlStyleEngine::layoutParameter(const QString &parameter) const
{
    Q_D(const QmlStyleEngine);
    // default to invalid value (-1)
    return d->layoutParameters.value(parameter, -1);
}

QColor QmlStyleEngine::colorParameter(const QString &parameter) const
{
    Q_D(const QmlStyleEngine);
    return d->colorParameters.value(parameter);
}

QString QmlStyleEngine::fontFamilyParameter(const QString &parameter) const
{
    Q_D(const QmlStyleEngine);
    return d->fontFamilyParameters.value(parameter);
}

void QmlStyleEngine::setPlatformStyle(const QString &newStyle)
{
    Q_D(QmlStyleEngine);
    if (d->mStyleName.compare(newStyle)) {
        d->mUseDefaultFallBackParams = false;
        d->mStyleName = newStyle;
       /* //resolve the correct directory, dont change the working style if not found
        QString workingDirectory(":/params/"+newStyle+"/");
        QDir dir;
        if (!dir.exists(workingDirectory)) {
            //dont have the correspoding files stay with existing style
            qWarning("failed to find relevant style directory falling back to default style");
            return;
        } else {
            d->mStyleName = newStyle;
            //check for valid layout params directory else use the default style layout params
            QString newLayoutDirectory(workingDirectory+"layouts/");
            if (dir.exists(newLayoutDirectory))
                d->mLayoutStyleDirectory = newLayoutDirectory;
            else {
                qWarning("failed to find layout definitions of current style,falling back to default style layout definitions.This is ok if only colorscheme was changed for the style");
                d->mLayoutStyleDirectory = QLatin1String(":/params/default/layouts/");
            }
            QString newColorDirectory(workingDirectory+"colors/");
            if (dir.exists(newColorDirectory))
                d->mColorSchemeDirectory = newColorDirectory;
            else {
                qWarning("failed to find color definitions of current style,falling back to default style color definitions.This is ok if only layoutparams was changed for the style");
                d->mColorSchemeDirectory = QLatin1String(":/params/default/colors/");
            }
        }*/
         d->updateLayoutParameters();
    }
}

void QmlStyleEngine::setColorScheme(const QString &newTheme)
{
    Q_D(QmlStyleEngine);
    if (d->mColorScheme.compare(newTheme)) {
        d->mColorScheme = newTheme;
        if (d->updateColorParameters())
            emit colorParametersChanged();
    }
}

#include "moc_qmlstyleengine.cpp"
