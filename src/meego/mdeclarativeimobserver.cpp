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

#include "mdeclarativeimobserver.h"

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <QInputContext>
#include <QApplication>
#include <QGraphicsObject>
#else
#include <QGuiApplication>
#include <QObject>
#endif
#include <QInputMethodEvent>

MDeclarativeIMObserver::MDeclarativeIMObserver(QDeclarativeItem *parent) :
        QDeclarativeItem(parent),
        m_omitInputMethodEvents(false)

{
}

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
bool MDeclarativeIMObserver::eventFilter(QObject *watched, QEvent *event)
#else
bool MDeclarativeIMObserver::sceneEventFilter(QGraphicsItem * watched, QEvent * event)
#endif
{
    if (event->type()==QEvent::InputMethod) {        
        if (m_omitInputMethodEvents) {
            return true;
        }

        QInputMethodEvent *ime = static_cast<QInputMethodEvent*>(event);
		QString newPreedit = ime->preeditString();
		
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        QObject *g = parentItem();
#else
        QGraphicsObject *g = parentObject();
#endif
        if (g != 0 && g->property("maximumLength").isValid()) {
            int maximumTextLength = g->property("maximumLength").toInt();
            int textLength = g->property("text").toString().length();
            int selectedTextLength = g->property("selectedText").toString().length();
            if (textLength == maximumTextLength &&
                newPreedit.length() - ime->replacementLength() > 0 &&
                selectedTextLength == 0) {
                    m_omitInputMethodEvents = true;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
                QInputPanel *ic = qApp->inputPanel();
#else
                QInputContext *ic = qApp->inputContext();
#endif
                    ic->reset();
                    m_omitInputMethodEvents = false;
                    return true;
            }				
        }

        if (newPreedit!=m_preedit) {
            m_preedit = newPreedit;
            emit preeditChanged();
        }
        
        QList<QInputMethodEvent::Attribute> attributes = ime->attributes();
        QList<QInputMethodEvent::Attribute>::iterator i;
        for (i = attributes.begin(); i != attributes.end(); ++i) {
            QInputMethodEvent::Attribute attribute = *i;
            if (attribute.type == QInputMethodEvent::Cursor) {
                m_preeditCursorPosition = attribute.start;
                emit preeditCursorPositionChanged();
            }
        }
    }

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    // standard event processing
    return QObject::eventFilter(watched, event);
#else
    return QDeclarativeItem::sceneEventFilter(watched,event);
#endif
}

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
void MDeclarativeIMObserver::itemChange(ItemChange c, const ItemChangeData & v)
{
    Q_UNUSED(v);
    if((parentItem() )&& (c==QQuickItem::ItemParentHasChanged
                          || c== QQuickItem::ItemSceneChange)){
        parentItem()->installEventFilter(this);
    }
}
#else
QVariant MDeclarativeIMObserver::itemChange(GraphicsItemChange c, const QVariant &v)
{
    if(c==QGraphicsItem::ItemParentHasChanged || c== QGraphicsItem::ItemSceneHasChanged){
        parentItem()->installSceneEventFilter(this);
    }
    return v;
}
#endif

