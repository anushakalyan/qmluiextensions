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

#ifndef QMLPLATFORMSTYLE_H
#define QMLPLATFORMSTYLE_H

#include <QObject>
#include <QtCore/qvariant.h>
#include <QtGui/qcolor.h>

class QmlPlatformStylePrivate;
class QmlStyleEngine;

class QmlPlatformStyle : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentStyle READ currentStyle WRITE setCurrentStyle NOTIFY currentStyleChanged FINAL)
    Q_PROPERTY(QString fontFamilyRegular READ fontFamilyRegular CONSTANT FINAL)
    Q_PROPERTY(int fontSizeLarge READ fontSizeLarge CONSTANT FINAL)
    Q_PROPERTY(int fontSizeMedium READ fontSizeMedium CONSTANT FINAL)
    Q_PROPERTY(int fontSizeSmall READ fontSizeSmall CONSTANT FINAL)
    Q_PROPERTY(int graphicSizeLarge READ graphicSizeLarge CONSTANT FINAL)
    Q_PROPERTY(int graphicSizeMedium READ graphicSizeMedium CONSTANT FINAL)
    Q_PROPERTY(int graphicSizeSmall READ graphicSizeSmall CONSTANT FINAL)
    Q_PROPERTY(int graphicSizeTiny READ graphicSizeTiny CONSTANT FINAL)
    Q_PROPERTY(int paddingLarge READ paddingLarge CONSTANT FINAL)
    Q_PROPERTY(int paddingMedium READ paddingMedium CONSTANT FINAL)
    Q_PROPERTY(int paddingSmall READ paddingSmall CONSTANT FINAL)
    Q_PROPERTY(int borderSizeMedium READ borderSizeMedium CONSTANT FINAL)
    Q_PROPERTY(int statusBarHeight READ statusBarHeight CONSTANT FINAL)
    Q_PROPERTY(int tabBarHeightPortrait READ tabBarHeightPortrait CONSTANT FINAL)
    Q_PROPERTY(int tabBarHeightLandscape READ tabBarHeightLandscape CONSTANT FINAL)
    Q_PROPERTY(int toolBarHeightPortrait READ toolBarHeightPortrait CONSTANT FINAL)
    Q_PROPERTY(int toolBarHeightLandscape READ toolBarHeightLandscape CONSTANT FINAL)
    Q_PROPERTY(int scrollBarThickness READ scrollBarThickness CONSTANT FINAL)
    Q_PROPERTY(int sliderThickness READ sliderThickness CONSTANT FINAL)
    Q_PROPERTY(int menuItemHeight READ menuItemHeight CONSTANT FINAL)
    Q_PROPERTY(int textFieldHeight READ textFieldHeight CONSTANT FINAL)
    Q_PROPERTY(int switchButtonHeight READ switchButtonHeight CONSTANT FINAL)
    Q_PROPERTY(int dialogMinSize READ dialogMinSize CONSTANT FINAL)
    Q_PROPERTY(int dialogMaxSize READ dialogMaxSize CONSTANT FINAL)
    Q_PROPERTY(int ratingIndicatorImageWidth READ ratingIndicatorImageWidth CONSTANT FINAL)
    Q_PROPERTY(int ratingIndicatorImageHeight READ ratingIndicatorImageHeight CONSTANT FINAL)
    Q_PROPERTY(int buttonSize READ buttonSize CONSTANT FINAL)

public:

    explicit QmlPlatformStyle(QmlStyleEngine *engine, QObject *parent = 0);
    ~QmlPlatformStyle();

    QString fontFamilyRegular() const;
    QString currentStyle() const;
    void setCurrentStyle(const QString &newstyle);

    int fontSizeLarge() const;
    int fontSizeMedium() const;
    int fontSizeSmall() const;
    int graphicSizeLarge() const;
    int graphicSizeMedium() const;
    int graphicSizeSmall() const;
    int graphicSizeTiny() const;
    int paddingLarge() const;
    int paddingMedium() const;
    int paddingSmall() const;
    int borderSizeMedium() const;

    int statusBarHeight() const;
    int tabBarHeightPortrait() const;
    int tabBarHeightLandscape() const;
    int toolBarHeightPortrait() const;
    int toolBarHeightLandscape() const;
    int scrollBarThickness() const;
    int sliderThickness() const;
    int menuItemHeight() const;
    int textFieldHeight() const;
    int switchButtonHeight() const;
    int dialogMinSize() const;
    int dialogMaxSize() const;
    int ratingIndicatorImageWidth() const;
    int ratingIndicatorImageHeight() const;
    int buttonSize() const;

Q_SIGNALS:
    void fontParametersChanged();
    void layoutParametersChanged();
    void currentStyleChanged();

protected:
    QScopedPointer<QmlPlatformStylePrivate> d_ptr;

private:
    Q_DISABLE_COPY(QmlPlatformStyle)
    Q_DECLARE_PRIVATE(QmlPlatformStyle)
};

#endif // QmlPlatformStyle_H
