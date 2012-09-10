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

#include "qmlplatformstyle.h"
#include "qmlstyleengine.h"


class QmlPlatformStylePrivate
{
public:
    QmlPlatformStylePrivate() {}
    QmlStyleEngine *engine;
};



QmlPlatformStyle::QmlPlatformStyle(QmlStyleEngine *engine, QObject *parent)
    : QObject(parent),
      d_ptr(new QmlPlatformStylePrivate())
{
    Q_D(QmlPlatformStyle);
    d->engine = engine;
    QObject::connect(engine, SIGNAL(fontParametersChanged()), this, SIGNAL(fontParametersChanged()));
    QObject::connect(engine, SIGNAL(layoutParametersChanged()), this, SIGNAL(layoutParametersChanged()));
}

QmlPlatformStyle::~QmlPlatformStyle()
{
}

QString QmlPlatformStyle::fontFamilyRegular() const
{
    Q_D(const QmlPlatformStyle);
    qDebug("fontFamilyRegular queried %s",qPrintable(d->engine->fontFamilyParameter(QLatin1String("font-family-regular"))));
    return d->engine->fontFamilyParameter(QLatin1String("font-family-regular"));
}

int QmlPlatformStyle::fontSizeLarge() const
{
    Q_D(const QmlPlatformStyle);
    qDebug("font size large queried %d",d->engine->layoutParameter(QLatin1String("font-size-large")));
    return d->engine->layoutParameter(QLatin1String("font-size-large"));
}

int QmlPlatformStyle::fontSizeMedium() const
{
    Q_D(const QmlPlatformStyle);
        qDebug("font size medium queried %d",d->engine->layoutParameter(QLatin1String("font-size-medium")));
    return d->engine->layoutParameter(QLatin1String("font-size-medium"));
}

int QmlPlatformStyle::fontSizeSmall() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("font-size-small"));
}

int QmlPlatformStyle::graphicSizeLarge() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("graphic-size-large"));
}

int QmlPlatformStyle::graphicSizeMedium() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("graphic-size-medium"));
}

int QmlPlatformStyle::graphicSizeSmall() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("graphic-size-small"));
}

int QmlPlatformStyle::graphicSizeTiny() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("graphic-size-tiny"));
}

int QmlPlatformStyle::paddingLarge() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("padding-large"));
}

int QmlPlatformStyle::paddingMedium() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("padding-medium"));
}

int QmlPlatformStyle::paddingSmall() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("padding-small"));
}

int QmlPlatformStyle::borderSizeMedium() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("border-size-medium"));
}

int QmlPlatformStyle::statusBarHeight() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("status-bar-height"));
}

int QmlPlatformStyle::tabBarHeightPortrait() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("tab-bar-height-portrait"));
}

int QmlPlatformStyle::tabBarHeightLandscape() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("tab-bar-height-landscape"));
}

int QmlPlatformStyle::toolBarHeightPortrait() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("tool-bar-height-portrait"));
}

int QmlPlatformStyle::toolBarHeightLandscape() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("tool-bar-height-landscape"));
}

int QmlPlatformStyle::scrollBarThickness() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("scroll-bar-thickness"));
}

int QmlPlatformStyle::sliderThickness() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("slider-thickness"));
}

int QmlPlatformStyle::menuItemHeight() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("menu-item-height"));
}

int QmlPlatformStyle::dialogMinSize() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("dialog-min-size"));
}

int QmlPlatformStyle::dialogMaxSize() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("dialog-max-size"));
}

int QmlPlatformStyle::textFieldHeight() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("text-field-height"));
}

int QmlPlatformStyle::switchButtonHeight() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("switch-button-height"));
}

int QmlPlatformStyle::ratingIndicatorImageWidth() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("rating-image-width"));
}

int QmlPlatformStyle::ratingIndicatorImageHeight() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("rating-image-height"));
}

int QmlPlatformStyle::buttonSize() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("button-size"));
}

QString QmlPlatformStyle::currentStyle() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->platformStyle();
}
void QmlPlatformStyle::setCurrentStyle(const QString &newstyle)
{
    Q_D(QmlPlatformStyle);
    d->engine->setPlatformStyle(newstyle);
}

