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
#include <QMetaObject>
#include <qobjectdefs.h>
#include <QFile>
#include <qmath.h>

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

    void init(QString styleName);
    bool updateLayoutParameters();
    void updateColorParameters();
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
    Q_DECLARE_PUBLIC(QmlStyleEngine)
};

void QmlStyleEnginePrivate::init(QString styleName)
{
    mStyleName = styleName;
    updateLayoutParameters();
    updateColorParameters();
    resolveFont();
}

void QmlStyleEnginePrivate::updateColorParameters()
{
    QString paramsFile;
    if (!mStyleName.compare("default"))
        paramsFile = QLatin1String(":/params/")+mStyleName+"/"+"colors"+"/"+"color.params";
    else {
        paramsFile = QLatin1String(":/params/")+mStyleName+"/"+"colors"+"/"+"color.params";
        if (!QFile::exists(paramsFile))
            paramsFile = QLatin1String(":/params/")+"default"+"/"+"colors"+"/"+"color.params";
    }
    loadParameters(paramsFile, ParameterType_Color);
}

bool QmlStyleEnginePrivate::updateLayoutParameters()
{
    MDeclarativeScreen *screen = MDeclarativeScreen::instance();
    QString longEdge = QString::number(qMax(screen->displayWidth(), screen->displayHeight()));
    QString shortEdge = QString::number(qMin(screen->displayWidth(), screen->displayHeight()));
    QString ppi = QString::number(qRound(screen->dpi() / 5.0) * 5); // round to closest 5
    QString newDisplayConfig = longEdge + QLatin1Char('_') + shortEdge + QLatin1Char('_') + ppi;

    if (displayConfig != newDisplayConfig) {
        layoutParameters.clear();
        QString layoutFile = QLatin1String(":/params/default/layouts/") + newDisplayConfig + QLatin1String(".params");
        if (QFile::exists(layoutFile))
            loadParameters(layoutFile, ParameterType_Integer);
        else
            loadParameters(QLatin1String(":/params/default/layouts/fallback.params"), ParameterType_Unit);
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

            QVariant value;
            QString valueStr = line.mid(colonId + 1).trimmed();
            if (type == ParameterType_Color) {
                // do implicit string-to-color conversion
                QColor color(valueStr);
                colorParameters.insert(line.left(colonId).trimmed(), color);
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
                layoutParameters.insert(line.left(colonId).trimmed(), intVal);
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

QmlStyleEngine::QmlStyleEngine(QObject *parent,QString styleName)
    : QObject(parent),
      d_ptr(new QmlStyleEnginePrivate())
{
    Q_D(QmlStyleEngine);
    d->q_ptr = this;
    // Screen size can change on desktop (RnD feature)
    QObject::connect(MDeclarativeScreen::instance(), SIGNAL(displayChanged()), this, SLOT(_q_displayChanged()));
    d->init(styleName);
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
    d->mStyleName = newStyle;
}

#include "moc_qmlstyleengine.cpp"
