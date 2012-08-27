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

#ifndef QMLWINDOWEVENTHANDLER_H
#define QMLWINDOWEVENTHANDLER_H

#include <qglobal.h>
#include <QObject>
#include "qmlwindowstate.h"
#include "mdeclarativescreen_bridge.h"

class QmlWindowEventHandler :public QObject
{
    Q_OBJECT
public:
    explicit QmlWindowEventHandler();
    virtual ~QmlWindowEventHandler();

    void startWindowStateTracking();
    bool isVisible() const;
    bool isActive() const;
    QmlWindowState::ViewMode viewMode() const;
    virtual bool platformSupportsSwipe() const;
    virtual void updateWindowOrientationAngle();
    virtual bool enableSupportForSwipe(bool newValue);
protected:
    enum FocusState { 
        FENone = 0,
        FEFocusIn = 1,
        FEFocusOut = 2
    };
    bool windowActivated(); //returns true if the window was visible atleast once in its life span.
    virtual void installFilter();
    virtual void focusChangeEvent(FocusState newFocusState);
    virtual void viewModeChangeEvent(QmlWindowState::ViewMode newViewMode = QmlWindowState::Fullsize);
    virtual void visibilityChangeEvent(bool visible);
    bool eventFilter(QObject *o, QEvent *e);
private:
    QmlWindowEventHandler::FocusState mFocusState;
    QmlWindowState::ViewMode mViewMode;
    bool mVisibile;
    bool mActive;
    Q_DISABLE_COPY(QmlWindowEventHandler)
};

#endif