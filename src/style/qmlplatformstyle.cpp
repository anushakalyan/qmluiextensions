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
    QObject::connect(engine, SIGNAL(colorParametersChanged()), this, SIGNAL(colorParametersChanged()));
}

QmlPlatformStyle::~QmlPlatformStyle()
{
}

QString QmlPlatformStyle::fontFamilyRegular() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->fontFamilyParameter(QLatin1String("font-family-regular"));
}

int QmlPlatformStyle::fontSizeLarge() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->layoutParameter(QLatin1String("font-size-large"));
}

int QmlPlatformStyle::fontSizeMedium() const
{
    Q_D(const QmlPlatformStyle);
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

QColor QmlPlatformStyle::colorBackground() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-background"));
}

QColor QmlPlatformStyle::colorNormalLight() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-light"));
}

QColor QmlPlatformStyle::colorNormalMid() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-mid"));
}

QColor QmlPlatformStyle::colorNormalDark() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-dark"));
}

QColor QmlPlatformStyle::colorNormalLink() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-link"));
}

QColor QmlPlatformStyle::colorPressed() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-pressed"));
}

QColor QmlPlatformStyle::colorLatched() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-latched"));
}

QColor QmlPlatformStyle::colorHighlighted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-highlighted"));
}

QColor QmlPlatformStyle::colorDisabledLight() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-disabled-light"));
}

QColor QmlPlatformStyle::colorDisabledMid() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-disabled-mid"));
}

QColor QmlPlatformStyle::colorDisabledDark() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-disabled-dark"));
}

QColor QmlPlatformStyle::colorTextSelection() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-text-selection"));
}

QColor QmlPlatformStyle::colorBackgroundInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-background-inverse"));
}

QColor QmlPlatformStyle::colorNormalLightInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-light-inverse"));
}

QColor QmlPlatformStyle::colorNormalMidInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-mid-inverse"));
}

QColor QmlPlatformStyle::colorNormalDarkInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-dark-inverse"));
}

QColor QmlPlatformStyle::colorNormalLinkInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-normal-link-inverse"));
}

QColor QmlPlatformStyle::colorPressedInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-pressed-inverse"));
}

QColor QmlPlatformStyle::colorLatchedInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-latched-inverse"));
}

QColor QmlPlatformStyle::colorHighlightedInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-highlighted-inverse"));
}

QColor QmlPlatformStyle::colorDisabledLightInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-disabled-light-inverse"));
}

QColor QmlPlatformStyle::colorDisabledMidInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-disabled-mid-inverse"));
}

QColor QmlPlatformStyle::colorDisabledDarkInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-disabled-dark-inverse"));
}

QColor QmlPlatformStyle::colorTextSelectionInverted() const
{
    Q_D(const QmlPlatformStyle);
    return d->engine->colorParameter(QLatin1String("color-text-selection-inverse"));
}

