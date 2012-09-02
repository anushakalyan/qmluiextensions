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

#include <qcoreevent.h>
#include <math.h>
#include <QMouseEvent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QPointF>
#include "qmlmousefilter.h"

static const int PressAndHoldDelay = 800;
// Threshold in QDeclarativeFlickable is 20, for press and hold we'll need 30 (30*30=900)
static const int FlickThresholdSquare = 900;

QmlMouseFilter::QmlMouseFilter(QQuickItem *parent) :
    QQuickItem(parent),
    pressAndHoldTimerId(-1),
    delayedPressEvent(0),
    lastPos(QPoint(0,0))
{
    setAcceptedMouseButtons(Qt::LeftButton);
}

QmlMouseFilter::~QmlMouseFilter()
{
    if(delayedPressEvent) {
        delete delayedPressEvent;
        delayedPressEvent = 0;
    }
}

void QmlMouseFilter::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId() == pressAndHoldTimerId) {
        killTimer(pressAndHoldTimerId);
        pressAndHoldTimerId = -1;
        QmlMouseEvent mdme(lastPos);

        emit pressAndHold(&mdme);
    }
}

void QmlMouseFilter::itemChange(ItemChange change, const ItemChangeData &)
{
    if (change == QQuickItem::ItemParentHasChanged || change == QQuickItem::ItemSceneChange) {
        if (parentItem()) {
            parentItem()->setFiltersChildMouseEvents(true);
            setKeepMouseGrab(true);
        }
    }
}

bool QmlMouseFilter::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type()) {
    case QEvent::MouseButtonDblClick: {
        QMouseEvent *me = static_cast <QMouseEvent *>(event);
        clampMousePosition(me);

        QPointF mappedPos = parentItem()->mapFromItem(this, me->screenPos());
        QmlMouseEvent mdme(mappedPos);
        emit doubleClicked(&mdme);
        if (mdme.isFiltered())
            return true;
        break;
    }
    case QEvent::MouseButtonPress: {
        QMouseEvent *me = static_cast <QMouseEvent *>(event);
        QPointF mappedPos = clampMousePosition(me);

        lastPos.setX(mappedPos.x());
        lastPos.setY(mappedPos.y());
        setKeepMouseGrab(true);
        if (delayedPressEvent) {
            delete delayedPressEvent;
            delayedPressEvent = 0;
        }
        delayedPressEvent = copyMouseEvent(me);
        // Launch press and hold timer
        pressAndHoldTimerId = startTimer(PressAndHoldDelay);
        QmlMouseEvent mdme(mappedPos);
        emit pressed(&mdme);
        if (mdme.isFiltered()) {
            me->accept();
            return true;
        }
        break;
    }
    case QEvent::MouseMove: {
        QMouseEvent *me = static_cast <QMouseEvent *>(event);
        QPointF dist = me->screenPos() - me->globalPos();

        clampMousePosition(me);

        QPointF mappedPos = parentItem()->mapFromItem(this, me->screenPos());
        lastPos.setX(mappedPos.x());
        lastPos.setY(mappedPos.y());
        QmlMouseEvent mdme(mappedPos);

        if (pressAndHoldTimerId != -1 && (dist.x() * dist.x()) + (dist.y() * dist.y()) > FlickThresholdSquare) {
            killTimer(pressAndHoldTimerId);
            pressAndHoldTimerId = -1;
            if (abs(dist.x()) < abs(dist.y())) {
                setKeepMouseGrab(false);
                if (canvas() && parentItem() && delayedPressEvent) {
                    canvas()->sendEvent(parentItem(), delayedPressEvent);
                    emit delayedPressSent();
                    return true;
                }
            } else {
                emit horizontalDrag();

                // Reset the mouse sequence to apply selectByMouse changes from QML side
                if (canvas() && parentItem() && delayedPressEvent) {
                    canvas()->sendEvent(parentItem(), delayedPressEvent);
                    return true;
                }
            }
        } else if (pressAndHoldTimerId == -1){
            emit mousePositionChanged(&mdme);
            if (mdme.isFiltered())
                return true;
        }
        if (pressAndHoldTimerId != -1) {
            return true;
        }
        break;
    }
    case QEvent::MouseButtonRelease: {
        if (pressAndHoldTimerId != -1) {
            killTimer(pressAndHoldTimerId);
            pressAndHoldTimerId=-1;
        }
        QMouseEvent *me = static_cast <QMouseEvent *>(event);
        QPointF mappedPos = clampMousePosition(me);
        mappedPos = parentItem()->mapFromItem(this, mappedPos);
        QmlMouseEvent mdme(mappedPos);

        emit released(&mdme);
        if (mdme.isFiltered()) {
            emit finished();
            return true;
        }
        bool ret = QQuickItem::eventFilter(obj,event);
        emit finished();
        return ret;
    }
    case QEvent::UngrabMouse: {
        if (pressAndHoldTimerId != -1) {
            killTimer(pressAndHoldTimerId);
            pressAndHoldTimerId=-1;
        }

        setKeepMouseGrab(true);
        break;
    }
    default:
        break;
    }

    return QQuickItem::eventFilter(obj,event);
}

QMouseEvent *QmlMouseFilter::copyMouseEvent (QMouseEvent *event)
{
    QMouseEvent *ret;
    ret = new QMouseEvent(event->type(),
                          QQuickItem::mapToItem(parentItem(),event->globalPos()),
                          event->globalPos(),
                          event->button(),
                          event->buttons(),
                          event->modifiers());
    ret->setAccepted(false);
    return ret;
}

QPointF QmlMouseFilter::clampMousePosition(QMouseEvent *me)
{
    // Clamp position in MouseFilter coordinates.
    // X position is clamped to MouseFilter area.
    // Y position is clamped to parent item area.
    QRectF targetRect = QRectF(0,-y(),width(),parentItem()->height());
    return QPointF(qBound(targetRect.x(), me->screenPos().x(),targetRect.x()+targetRect.width()),
        qBound(targetRect.y(), me->screenPos().y(), targetRect.y()+targetRect.height()-1));
}
