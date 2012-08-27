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

#include <QWidget>
#include <QApplication>
#include "qmlwindowstate.h"
#include "qmlwindowstate_p.h"
#include "qmlwindoweventhandler.h"

QmlWindowStatePrivate * QmlWindowStatePrivate::instance = NULL;

namespace
{
    const unsigned int VisibleChangedDelay = 1000;
}

QmlWindowStatePrivate::QmlWindowStatePrivate()
{
    QmlWindowStatePrivate::instance = this;
    animating = false;
}

QmlWindowState::~QmlWindowState()
{
    delete d_ptr;
}

QmlWindowStatePrivate::~QmlWindowStatePrivate()
{
    delete mWindowStateHelper;
}

void QmlWindowStatePrivate::constructHelper()
{
#if defined HAVE_MEEGOGRAPHICSSYSTEM && defined HAVE_MEEGOTOUCH
    mWindowStateHelper = new QmlXWindowEventHandler();
#else
    mWindowStateHelper = new QmlWindowEventHandler();
#endif
}

void QmlWindowStatePrivate::initVisibleChangedTimer()
{
    Q_Q(QmlWindowState);
    visibleChangedTimer.connect(&visibleChangedTimer, SIGNAL(timeout()),
                                q, SLOT(_q_doVisibleChangedNotVisible()));
    visibleChangedTimer.setInterval(VisibleChangedDelay);
    visibleChangedTimer.setSingleShot(true);
}

void QmlWindowStatePrivate::doActiveChanged()
{
    Q_Q(QmlWindowState);
    emit q->activeChanged();
}

void QmlWindowStatePrivate::_q_doVisibleChangedNotVisible()
{
    Q_Q(QmlWindowState);
    // Check that window is fully obscured and thumbnail is
    // not being seen in the switcher
    if (!mWindowStateHelper->isVisible()) {
        emit q->visibleChanged();
    }
}

void QmlWindowStatePrivate::doViewModeChanged()
{
    Q_Q(QmlWindowState);
    emit q->viewModeChanged();
}


bool QmlWindowStatePrivate::allowSwipe() const
{
    return mWindowStateHelper->platformSupportsSwipe();
}

bool QmlWindowStatePrivate::setAllowSwipe(bool newValue)
{
    return mWindowStateHelper->enableSupportForSwipe(newValue);
}

void QmlWindowStatePrivate::doVisibleChanged(bool newVisible,bool hasFocus)
{
    Q_Q(QmlWindowState);

    // Emit visibleChanged() immediately if we are becaming
    // visible. Otherwise we need to wait a bit due to possible race
    // between _MEEGOTOUCH_VISIBLE_IN_SWITCHER and X11's visibility
    // events (that race condition causes oscillation).
        if (newVisible) {
            visibleChangedTimer.stop();
            emit q->visibleChanged();
            // Set the window active if it was before
            if (hasFocus) {
                doActiveChanged();
            }
        } else {
            visibleChangedTimer.start();
            // Set the window not active
            doActiveChanged();
        }
}

void QmlWindowState::_q_doVisibleChangedNotVisible()
{
    Q_D(QmlWindowState);
    d->_q_doVisibleChangedNotVisible();
}

static QmlWindowState *self = 0;

QmlWindowState* QmlWindowState::instance()
{
    if (!self)
        self = new QmlWindowState();
    return self;
}

QmlWindowState::QmlWindowState(QObject *parent) :
    QObject(parent),
    d_ptr(new QmlWindowStatePrivate)
{
    Q_D(QmlWindowState);
    d->q_ptr = this;
    d->constructHelper();
    d->initVisibleChangedTimer();
}

QmlWindowState::ViewMode QmlWindowState::viewMode() const
{
    Q_D(const QmlWindowState);
    return d->mWindowStateHelper->viewMode();
}

QString QmlWindowState::viewModeString() const
{
    Q_D(const QmlWindowState);

    const char *s = 0;
    switch (d->mWindowStateHelper->viewMode()) {
    case Fullsize:
        s = "Fullsize";
        break;
    case Thumbnail:
        s = "Thumbnail";
        break;
    }

    return QString::fromLatin1(s);
}

bool QmlWindowState::visible() const
{
    Q_D(const QmlWindowState);
    return d->mWindowStateHelper->isVisible();
}

bool QmlWindowState::active() const
{
    Q_D(const QmlWindowState);
    return d->mWindowStateHelper->isActive();
}

bool QmlWindowState::animating() const
{
    Q_D(const QmlWindowState);
    return d->animating;
}

void QmlWindowState::setAnimating(bool animatingStatus)
{
    Q_D(QmlWindowState);
    if (animatingStatus != d->animating) {
        d->animating = animatingStatus;
        emit animatingChanged();
    }
}

void QmlWindowState::updateWindowOrientationAngle()
{
    Q_D(QmlWindowState);
    d->mWindowStateHelper->updateWindowOrientationAngle();
}




