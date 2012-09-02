/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore/qcoreevent.h>
#include "qapplication_bridge.h"
#include <QDebug>
#include "qmlwindoweventhandler.h"
#include "qmlwindowstate_p.h"

static bool mFirstFocusChange = true;


QmlWindowEventHandler::QmlWindowEventHandler()
    :mFocusState(QmlWindowEventHandler::FENone)
    ,mViewMode(QmlWindowState::Fullsize)
    ,mVisibile(false)
    ,mActive(false)
{
    installFilter();
}

QmlWindowEventHandler::~QmlWindowEventHandler()
{
    MDeclarativeScreen::instance()->removeEventFilter(this);
}

void QmlWindowEventHandler::focusChangeEvent(QmlWindowEventHandler::FocusState newFocusState)
{
    if (mFocusState == newFocusState)
        return;
    mFocusState = newFocusState;
    if (mFocusState == FEFocusIn) {
        // The event filter is installed at a too late stage to catch
        // the first VisibilityNotify. This causes the window to be
        // invisible from WindowState's point of view until the
        // next VisibilityNotify.
        //
        // To correct this we explicitly set the window to be visible
        // and fullsize when the first FocusIn event arrives. To keep
        // the functionality as transparent as possible,
        // doActiveChanged() is called _after_ the visibility is
        // changed.
        //
        mActive = true;
        if (mFirstFocusChange && !mVisibile) {
            mFirstFocusChange = false;
            viewModeChangeEvent();
            visibilityChangeEvent(true);
        }
        QmlWindowState::instance()->d_ptr->doActiveChanged();
    } else {
        mActive = false;
        QmlWindowState::instance()->d_ptr->doActiveChanged();
    }
}

bool QmlWindowEventHandler::windowActivated()
{
    return mFirstFocusChange;
}

void QmlWindowEventHandler::viewModeChangeEvent(QmlWindowState::ViewMode newViewMode)
{
    if (mViewMode == newViewMode)
        return;
    mViewMode = newViewMode;
    QmlWindowState::instance()->d_ptr->doViewModeChanged();
}

void QmlWindowEventHandler::visibilityChangeEvent(bool visible)
{
    if (mVisibile == visible)
        return;
    mVisibile = visible;
    QmlWindowState::instance()->d_ptr->doVisibleChanged(mVisibile,mActive);
}

void QmlWindowEventHandler::updateWindowOrientationAngle()
{

}

bool QmlWindowEventHandler::platformSupportsSwipe() const
{
    return false;
}

bool QmlWindowEventHandler::enableSupportForSwipe(bool newValue)
{
    Q_UNUSED(newValue);
    return false;
}

bool QmlWindowEventHandler::isVisible() const
{
    qDebug()<<"queried visibe state"<<mVisibile;
    return mVisibile;
}

bool QmlWindowEventHandler::isActive() const
{
    qDebug()<<"queried activate state"<<mActive;
    return mActive;
}

QmlWindowState::ViewMode QmlWindowEventHandler::viewMode() const
{
    qDebug()<<"queried view mode state"<<mViewMode;
    return mViewMode;
}

bool QmlWindowEventHandler::eventFilter(QObject *obj, QEvent *event)
{
    if (obj->parent() == NULL) {
        bool isTopLevelWidget = false;
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        mTopLevelWindow = qobject_cast<QWindow*>(obj);
        isTopLevelWidget = !mTopLevelWindow ?false:true;
#else
        QWidget* w  = qobject_cast<QWidget*>(obj);
        isTopLevelWidget = !w ?false:true;
#endif
        if (isTopLevelWidget) {
            if (event->type() == QEvent::FocusIn){
                focusChangeEvent(QmlWindowEventHandler::FEFocusIn);
                qDebug() << "Recieved focusin";
            } else if (event->type() == QEvent::FocusOut){
                focusChangeEvent(QmlWindowEventHandler::FEFocusOut);
                qDebug() << "Recieved focusout";
            } else if (event->type() == QEvent::Show){
                visibilityChangeEvent(true);
                qDebug() << "Recieved show";
            } else if (event->type() == QEvent::Hide){
                visibilityChangeEvent(false);
                qDebug() << "Recieved Hide";
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void QmlWindowEventHandler::installFilter()
{
    qApp->installEventFilter(this);
}








