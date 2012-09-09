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

#include "qmlstylefactory.h"
#include "qmlstyleengine.h"
#include "qmlplatformstyle.h"
#include "qmlthemeparams.h"
#include <QObject>

class QmlStyleFactoryPrivate
{
public:
    QmlStyleFactoryPrivate() {}

    QmlStyleEngine *mEngine;
    QmlPlatformStyle *mPlatformStyle;
    QmlThemeParams *mThemeParams;
};

QmlStyleFactory::QmlStyleFactory(QObject *parent)
    : QObject(parent),
      d_ptr(new QmlStyleFactoryPrivate())
{
    Q_D(QmlStyleFactory);
    d->mEngine = new QmlStyleEngine(QLatin1String("default"),QLatin1String("default"),this);
    d->mPlatformStyle = new QmlPlatformStyle(d->mEngine, this);
    d->mThemeParams = new QmlThemeParams(d->mEngine, this);
}

QmlStyleFactory::~QmlStyleFactory()
{
}

QObject *QmlStyleFactory::platformStyle() const
{
    Q_D(const QmlStyleFactory);
    return d->mPlatformStyle;
}

QObject *QmlStyleFactory::themeParams() const
{
    Q_D(const QmlStyleFactory);
    return d->mThemeParams;
}

