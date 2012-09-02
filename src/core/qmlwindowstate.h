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

#ifndef QMLWINDOWSTATE_H
#define QMLWINDOWSTATE_H

#include <qglobal.h>

#ifdef HAVE_MALIIT
#include <maliit/inputmethod.h>
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <qqml.h>
#else
#include <qdeclarative.h>
#endif

class QmlWindowStatePrivate;

// QmlWindowState provides visibility information,supported platform specific attributes
// of the window associated to a QML application.
class QmlWindowState : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool visible READ visible NOTIFY visibleChanged FINAL)
    Q_PROPERTY(bool active READ active NOTIFY activeChanged FINAL)
    Q_PROPERTY(bool animating READ animating WRITE setAnimating NOTIFY animatingChanged FINAL)
    Q_PROPERTY(ViewMode viewMode READ viewMode NOTIFY viewModeChanged FINAL)
    Q_PROPERTY(QString viewModeString READ viewModeString NOTIFY viewModeChanged FINAL)

    Q_ENUMS(ViewMode)

public:

    Q_INVOKABLE void startSipOrientationChange(int newOrientation) {
#ifdef HAVE_MALIIT
        Maliit::OrientationAngle newOrientationAngle = static_cast<Maliit::OrientationAngle>(newOrientation);
        Maliit::InputMethod::instance()->startOrientationAngleChange(newOrientationAngle);
#else
        Q_UNUSED(newOrientation)
#endif
    }
    
    Q_INVOKABLE void finishSipOrientationChange(int newOrientation) {
#ifdef HAVE_MALIIT
        Maliit::OrientationAngle newOrientationAngle = static_cast<Maliit::OrientationAngle>(newOrientation);
        Maliit::InputMethod::instance()->setOrientationAngle(newOrientationAngle);
#else
        Q_UNUSED(newOrientation)
#endif
    }

    // Possible view modes for a window:
    // - Fullsize for a window that is in the maximized state.
    //   This is the default state.
    // - Thumbnail for a window that is minimized to the switcher.
    //   Thumbnail mode is activated when the window can be seen
    //   in the switcher.
    enum ViewMode {
        Fullsize,
        Thumbnail
    };

    static QmlWindowState* instance();
    ~QmlWindowState();

    // Return the current view mode
    ViewMode viewMode() const;

    // Return the current view mode as a string:
    // - "Fullsize" for Fullsize
    // - "Thumbnail" for Thumbnail
    QString viewModeString() const;

    // Returns true, if the window or its thumbnail can be seen.
    // Returns false, if the window or its thumbnail has been hidden
    // at least for 1000 ms.
    bool visible() const;

    // Return true, if the window is active (has focus).
    bool active() const;

    // Return true, if the window orientation is animated
    bool animating() const;

    void setAnimating(bool animatingStatus);
    void updateWindowOrientationAngle();

Q_SIGNALS:

    // Signal that is emitted when active-property changes.
    void activeChanged();

    // Signal that is emitted when viewMode-property changes.
    void viewModeChanged();

    // Signal that is emitted when visible-property changes.
    void visibleChanged();

    // Signal that is emitted when orientation animation starts or finishes.
    void animatingChanged();
protected:

    QmlWindowStatePrivate *const d_ptr;

private:
    explicit QmlWindowState(QObject *parent = 0);
    Q_DECLARE_PRIVATE(QmlWindowState)
    Q_DISABLE_COPY(QmlWindowState)

private Q_SLOTS:
    void _q_doVisibleChangedNotVisible();

#ifdef UNIT_TEST
    friend class tst_MWindowState;
#endif // UNIT_TEST
    friend class QmlWindowEventHandler;
    friend class MDeclarativeScreen;
};

QML_DECLARE_TYPE(QmlWindowState)
#endif // MWINDOWSTATE_H

