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

#ifndef QMLTHEMEPLUGIN_H
#define QMLTHEMEPLUGIN_H

#include <qglobal.h>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <qqml.h>
#else
#include <qdeclarative.h>
#endif
#include <QtGui/qcolor.h>
class QmlThemeParamsPrivate;
class QmlStyleEngine;
QT_FORWARD_DECLARE_CLASS(QString)

class QmlThemeParams : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool inverted READ isInverted WRITE setInverted NOTIFY invertedChanged FINAL)
    Q_PROPERTY(QString colorScheme READ colorScheme WRITE setColorScheme NOTIFY colorSchemeChanged FINAL)
    Q_PROPERTY(QString colorString READ colorString NOTIFY colorStringChanged FINAL)
    Q_PROPERTY(QColor textColor READ textColor CONSTANT FINAL)
    Q_PROPERTY(QColor pressedTextColor READ pressedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor disabledTextColor READ disabledTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor checkedTextColor READ checkedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectedTextColor READ selectedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionTextColor READ selectionTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor promptTextColor READ promptTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor dialogTitleBarColor READ dialogTitleBarColor CONSTANT FINAL)
    Q_PROPERTY(QColor dialogTitleBarTextColor READ dialogTitleBarTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor dialogMessageTextColor READ dialogMessageTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor windowBackgroundColor READ windowBackgroundColor CONSTANT FINAL)
    Q_PROPERTY(QColor highlightedTextColor READ highlightedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor sectionScrollerTextColor READ sectionScrollerTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogForegroundColor READ selectionDialogForegroundColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogSecondaryForegroundColor READ selectionDialogSecondaryForegroundColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogBackgroundColor READ selectionDialogBackgroundColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogSelectColor READ selectionDialogSelectColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogCommonLabelColor READ selectionDialogCommonLabelColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogItemTextColor READ selectionDialogItemTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogItemSelectedTextColor READ selectionDialogItemSelectedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogItemBackgroundColor READ selectionDialogItemBackgroundColor CONSTANT FINAL)
    Q_PROPERTY(QColor selectionDialogItemSelectedBackgroundColor READ selectionDialogItemSelectedBackgroundColor CONSTANT FINAL)
    Q_PROPERTY(QColor listTitleColor READ listTitleColor CONSTANT FINAL)
    Q_PROPERTY(QColor listTitlePressedColor READ listTitlePressedColor CONSTANT FINAL)
    Q_PROPERTY(QColor listSubTitleColor READ listSubTitleColor CONSTANT FINAL)
    Q_PROPERTY(QColor listSubTitlePressedColor READ listSubTitlePressedColor CONSTANT FINAL)
    Q_PROPERTY(QColor negitiveButtonTextColor READ negitiveButtonTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor negitiveButtonPressedTextColor READ negitiveButtonPressedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor negitiveButtonLatchedTextColor READ negitiveButtonLatchedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor positiveButtonTextColor READ positiveButtonTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor positiveButtonPressedTextColor READ positiveButtonPressedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor positiveButtonLatchedTextColor READ positiveButtonLatchedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor tabButtonTextColor READ tabButtonTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor tabButtonPressedTextColor READ tabButtonPressedTextColor CONSTANT FINAL)
    Q_PROPERTY(QColor tabButtonLatchedTextColor READ tabButtonLatchedTextColor CONSTANT FINAL)

public:
    QmlThemeParams(QmlStyleEngine *engine,QObject *parent = 0);
    virtual ~QmlThemeParams();

    bool isInverted() const;
    void setInverted(bool inverted);
    QString colorScheme() const;
    void setColorScheme(QString colorScheme);
    QString colorString() const;

    QColor textColor() const;
    QColor pressedTextColor() const;
    QColor disabledTextColor() const;
    QColor checkedTextColor() const;
    QColor selectedTextColor() const;
    QColor selectionTextColor() const;
    QColor promptTextColor() const;
    QColor dialogTitleBarColor() const;
    QColor dialogTitleBarTextColor() const;
    QColor dialogMessageTextColor() const;
    QColor windowBackgroundColor() const;
    QColor highlightedTextColor() const;
    QColor sectionScrollerTextColor() const;
    QColor selectionDialogForegroundColor() const;
    QColor selectionDialogSecondaryForegroundColor() const;
    QColor selectionDialogBackgroundColor() const;
    QColor selectionDialogSelectColor() const;
    QColor selectionDialogCommonLabelColor() const;
    QColor selectionDialogItemTextColor() const;
    QColor selectionDialogItemSelectedTextColor() const;
    QColor selectionDialogItemBackgroundColor() const;
    QColor selectionDialogItemSelectedBackgroundColor() const;
    QColor listTitleColor() const;
    QColor listTitlePressedColor() const;
    QColor listSubTitleColor() const;
    QColor listSubTitlePressedColor() const;
    QColor negitiveButtonTextColor() const;
    QColor negitiveButtonPressedTextColor() const;
    QColor negitiveButtonLatchedTextColor() const;
    QColor positiveButtonTextColor() const;
    QColor positiveButtonPressedTextColor() const;
    QColor positiveButtonLatchedTextColor() const;
    QColor tabButtonTextColor() const;
    QColor tabButtonPressedTextColor() const;
    QColor tabButtonLatchedTextColor() const;

Q_SIGNALS:
    void invertedChanged();
    void colorSchemeChanged();
    void colorStringChanged();
    void selectionColorChanged();

protected:
    QScopedPointer<QmlThemeParamsPrivate> d_ptr;

private:
    Q_DISABLE_COPY(QmlThemeParams)
    Q_DECLARE_PRIVATE(QmlThemeParams)
};

QML_DECLARE_TYPE(QmlThemeParams)
#endif // QmlThemeParams_H
