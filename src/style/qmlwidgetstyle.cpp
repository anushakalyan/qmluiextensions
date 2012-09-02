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

#define QT_NO_CAST_FROM_ASCII
#define QT_NO_CAST_TO_ASCII

#include <QObject>
#include <QFileInfo>
#include <QFontMetrics>

#ifdef HAVE_MOBILITY
#include <QFeedbackEffect>
#endif //HAVE_MOBILITY
#include <QtWidgets/QApplication>
#include "qmlwidgetstyle.h"
#include "qmlstyleengine.h"


class QmlWidgetStylePrivate
{
public:
    QmlWidgetStylePrivate() {}

    QmlStyleEngine *engine;
};

QmlWidgetStyle::QmlWidgetStyle(QmlStyleEngine *engine, QObject *parent)
    : QObject(parent),
      d_ptr(new QmlWidgetStylePrivate())
{
    Q_D(QmlWidgetStyle);
    d->engine = engine;
    QObject::connect(engine, SIGNAL(layoutParametersChanged()), this, SIGNAL(layoutParametersChanged()));
    QObject::connect(engine, SIGNAL(colorParametersChanged()), this, SIGNAL(colorParametersChanged()));
}

QmlWidgetStyle::~QmlWidgetStyle()
{
}

int QmlWidgetStyle::statusBarHeight() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("status-bar-height"));
}

int QmlWidgetStyle::tabBarHeightPortrait() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("tab-bar-height-portrait"));
}

int QmlWidgetStyle::tabBarHeightLandscape() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("tab-bar-height-landscape"));
}

int QmlWidgetStyle::toolBarHeightPortrait() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("tool-bar-height-portrait"));
}

int QmlWidgetStyle::toolBarHeightLandscape() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("tool-bar-height-landscape"));
}

int QmlWidgetStyle::scrollBarThickness() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("scroll-bar-thickness"));
}

int QmlWidgetStyle::sliderThickness() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("slider-thickness"));
}

int QmlWidgetStyle::menuItemHeight() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("menu-item-height"));
}

int QmlWidgetStyle::dialogMinSize() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("dialog-min-size"));
}

int QmlWidgetStyle::dialogMaxSize() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("dialog-max-size"));
}

int QmlWidgetStyle::textFieldHeight() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("text-field-height"));
}

int QmlWidgetStyle::switchButtonHeight() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("switch-button-height"));
}

int QmlWidgetStyle::ratingIndicatorImageWidth() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("rating-image-width"));
}

int QmlWidgetStyle::ratingIndicatorImageHeight() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("rating-image-height"));
}

int QmlWidgetStyle::buttonSize() const
{
    Q_D(const QmlWidgetStyle);
    return d->engine->layoutParameter(QLatin1String("button-size"));
}

void QmlWidgetStyle::play(int effect)
{
#ifdef HAVE_MOBILITY
    QtMobility::QFeedbackEffect::playThemeEffect(static_cast<QtMobility::QFeedbackEffect::ThemeEffect>(effect));
#else
    Q_UNUSED(effect);
#endif //HAVE_MOBILITY
}

int QmlWidgetStyle::textWidth(const QString &text, const QFont &font) const
{
    QFontMetrics metrics(font);
    return metrics.width(text) + 1; //Fix QTCOMPONENTS-810
}

int QmlWidgetStyle::fontHeight(const QFont &font) const
{
    QFontMetrics metrics(font);
    return metrics.height();
}

QUrl QmlWidgetStyle::toolBarIconPath(const QUrl &path, bool inverted) const
{
    if (!path.isEmpty()) {
        const QString scheme = path.scheme();
        const QFileInfo fileInfo = path.path();
        const QString completeBaseName = fileInfo.completeBaseName();

        if ((scheme.isEmpty() || scheme == QLatin1String("file") || scheme == QLatin1String("qrc"))
            && completeBaseName.startsWith(QLatin1String("toolbar-"))
            && completeBaseName.lastIndexOf(QLatin1Char('.')) == -1)
                return imagePath(completeBaseName, inverted);
    }
    return path;
}

QString QmlWidgetStyle::imagePath(const QString &path, bool inverted) const
{
    QLatin1String invertedSuffix(inverted ? "_inverse" : "");
    return QLatin1String("image://theme/") + path + invertedSuffix;
}

bool QmlWidgetStyle::isTabBarIcon(const QUrl &url) const
{
    if (url.isEmpty() || url.scheme() == QLatin1String("http"))
        return false;

    QFileInfo fileInfo = url.path();
    QString suffix = fileInfo.suffix();

    return suffix.toLower() == QLatin1String("svg") || suffix.isEmpty();
}

int QmlWidgetStyle::startDragDistance() const
{
    return QApplication::startDragDistance();
}
