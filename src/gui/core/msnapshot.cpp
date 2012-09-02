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

#include "msnapshot.h"
#include <qpainter.h>

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
#include <qgraphicsscene.h>
MSnapshot::MSnapshot(QDeclarativeItem *parent)
    : QDeclarativeItem(parent), sWidth(0), sHeight(0)
{
    setFlag(ItemHasNoContents, false);
    setFlag(ItemIgnoresParentOpacity, true);
    setOpacity(0);
}
#else
MSnapshot::MSnapshot(QQuickPaintedItem *parent)
    : QQuickPaintedItem(parent), sWidth(0), sHeight(0)
{
   /* setFlag(ItemHasNoContents, false);
    setFlag(ItemIgnoresParentOpacity, true);
    setOpacity(0);*/
    setAntialiasing(true);
}
#endif

MSnapshot::~MSnapshot()
{
}

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
void MSnapshot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
#else
void MSnapshot::paint(QPainter *painter)
#endif
{
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
    painter->save();
    if (smooth()) {
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    }
    painter->drawPixmap(0, 0, snapshot);
    painter->restore();
#else
    painter->drawImage(0, 0, snapshot);
#endif
}

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
void MSnapshot::take()
{
    QGraphicsScene *s = scene();
    if (!s)
        return;
    snapshot = QPixmap(width(), height());
    QPainter painter(&snapshot);
    QRectF r(0, 0, snapshotWidth(), snapshotHeight());
    s->render(&painter, r, r);
}
#else
void MSnapshot::take()
{
    QGraphicsScene *s = scene();
    if (!s)
        return;
    QRectF bound = contentsBoundingRect();
    snapshot = QImage(width(), height());
    QPainter painter(&snapshot);
    s->render(&painter,bound, bound);
}
#endif

void MSnapshot::free()
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        snapshot = QImage();
#else
        snapshot = QPixmap();
#endif
}

void MSnapshot::setSnapshotWidth(int width)
{
    if (sWidth != width) {
        sWidth = width;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        setContentsSize(sWidth,sHeight);
#endif
        emit snapshotWidthChanged();
    }
}

void MSnapshot::setSnapshotHeight(int height)
{
    if (sHeight != height) {
        sHeight = height;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        setContentsSize(sWidth,sHeight);
#endif
        emit snapshotHeightChanged();
    }
}

int MSnapshot::snapshotWidth() const
{
    return sWidth;
}

int MSnapshot::snapshotHeight() const
{
    return sHeight;
}
