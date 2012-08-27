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

#ifndef QMLWINDOWEVENTHANDLER_X11_H
#define QMLWINDOWEVENTHANDLER_X11_H

#include "../../experimental/QmlUiExtensions/core/qmlwindoweventhandler.h"
#include <qwindowdefs.h>
#include "mx11wrapper.h"
#include <QAbstractNativeEventFilter>

class QmlXWindowEventHandler : public QmlWindowEventHandler, public QAbstractNativeEventFilter
{
public:
    explicit QmlXWindowEventHandler();
    virtual ~QmlXWindowEventHandler();
    void updateWindowOrientationAngle();
    bool enableSupportForSwipe(bool enabled);
    bool platformSupportsSwipe() const;
private: 
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
    void handleXVisibilityEvent(XVisibilityEvent *xevent);
    void handleXFocusChangeEvent(XFocusChangeEvent *xevent);
    void handleXPropertyEvent(XPropertyEvent *xevent);
    void writeX11OrientationAngleProperty();
    void installFilter();
    static bool isMeeGoWindowManagerRunning();
    static bool handlePlatformEvent(void *message, long int *result);
    static QmlXWindowEventHandler *instance;
    bool meegoCompositor();
    WId windowId;
    bool mSwipeSupport;
    Q_DISABLE_COPY(QmlXWindowEventHandler)
};
#endif
