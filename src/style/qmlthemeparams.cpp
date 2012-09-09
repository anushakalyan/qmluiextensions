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

#include <QtCore/qstring.h>
#include <QPointer>
#include "qmlthemeparams.h"
#include "qmlstyleengine.h"
#include <QDebug>

class QmlThemeParamsPrivate
{
public:
    QmlThemeParamsPrivate(QmlStyleEngine *engine)
    {
        mEngine = engine;
        mInverted = false;
        mColorScheme = "1";
        mColorString = "";
    }

    QmlStyleEngine *mEngine;
    bool mInverted;
    QString mColorScheme;
    QString mColorString;
};

QmlThemeParams::QmlThemeParams(QmlStyleEngine *engine, QObject *parent)
    : QObject(parent)
    ,d_ptr(new QmlThemeParamsPrivate(engine))
{

}

QmlThemeParams::~QmlThemeParams()
{
}

bool QmlThemeParams::isInverted() const
{
    Q_D(const QmlThemeParams);
    return d->mInverted;
}

void QmlThemeParams::setInverted(bool inverted)
{
    Q_D(QmlThemeParams);
    if (d->mInverted != inverted) {
        d->mInverted = inverted;
        emit invertedChanged();
    }
}

QString QmlThemeParams::colorScheme() const
{
    Q_D(const QmlThemeParams);
    return d->mColorScheme;
}

void QmlThemeParams::setColorScheme(QString color)
{
    Q_D(QmlThemeParams);
    QString cs;
    QString sc;
    if (d->mColorScheme != color) {
        d->mColorScheme = color;
        emit colorSchemeChanged();
    }
    if (color == "2" || color == "lightGreen" || color == "green1") {
        cs = "color2-";
        sc = "#62B700";
    } else if (color == "3" || color == "green" || color == "green2") {
        cs = "color3-";
        sc = "#3D890C";
    } else if (color == "4" || color == "darkGreen" || color == "green3") {
        cs = "color4-";
        sc = "#347708";
    } else if (color == "5" || color == "darkestGreen" || color == "green4") {
        cs = "color5-";
        sc = "#306600";
    } else if (color == "6" || color == "lightBlue" || color == "blue1") {
        cs = "color6-";
        sc = "#870CBA";
    } else if (color == "7" || color == "blue" || color == "blue2") {
        cs = "color7-";
        sc = "#09A7CC";
    } else if (color == "8" || color == "darkBlue" || color == "blue3") {
        cs = "color8-";
        sc = "#0067BC";
    } else if (color == "9" || color == "darkestBlue" || color == "blue4") {
        cs = "color9-";
        sc = "#1C51AF";
    } else if (color == "10" || color == "darkPurple" || color == "purple2") {
        cs = "color10-";
        sc = "#6400BC";
    } else if (color == "11" || color == "purple" || color == "purple1") {
        cs = "color11-";
        sc = "#870CBA";
    } else if (color == "12" || color == "pink" || color == "pink2") {
        cs = "color12-";
        sc = "#CC09BA";
    } else if (color == "13" || color == "lightPink" || color == "pink1") {
        cs = "color13-";
        sc = "#E800A1";
    } else if (color == "14" || color == "lightOrange" || color == "orange1") {
        cs = "color14-";
        sc = "#EF5500";
    } else if (color == "15" || color == "orange" || color == "orange2") {
        cs = "color15-";
        sc = "#EA650A";
    } else if (color == "16" || color == "darkOrange" || color == "orange3") {
        cs = "color16-";
        sc = "#F77219";
    } else if (color == "17" || color == "darkYellow" || color == "yellow3") {
        cs = "color17-";
        sc = "#FF8500";
    } else if (color == "18" || color == "yellow" || color == "yellow2") {
        cs = "color18-";
        sc = "#ED9507";
    } else if (color == "19" || color == "lightYellow" || color == "yellow1") {
        cs = "color19-";
        sc = "#F2B111";
    } else {
        cs = "";
        sc = "#4591ff";
    }
    if (cs != d->mColorString) {
        d->mColorString = cs;
        emit colorStringChanged();
    }
    /*if (sc != d->mSelectionColor) {
        d->mSelectionColor = sc;
        emit selectionColorChanged();
    }*/
}

QString QmlThemeParams::colorString() const
{
    Q_D(const QmlThemeParams);
    return d->mColorString;
}

QColor QmlThemeParams::textColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "textinverse":"text";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::pressedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "pressedinverse":"pressed";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::disabledTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "disabledtextinverse":"disabledtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::checkedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "latchedinverse":"latched";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "textselectedinverse":"textselected";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "textselectioninverse":"textselection";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::promptTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "prompttextinverse":"prompttext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::dialogTitleBarColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "dialogtitlebarinverse":"dialogtitlebar";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::dialogTitleBarTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "dialogtitletextinverse":"dialogtitletext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::dialogMessageTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "dialogmessagetextinverse":"dialogmessagetext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::windowBackgroundColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "windowbackgroundinverse":"windowbackground";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::highlightedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "highlightedinverse":"highlighted";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::sectionScrollerTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "sectionscrollertextinverse":"sectionscrollertext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogForegroundColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogforegroundinverse":"selectiondialogforeground";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogSecondaryForegroundColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogsecondaryforegroundinverse":"selectiondialogsecondaryforeground";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogBackgroundColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogbackgroundinverse":"selectiondialogbackground";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogSelectColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogselectinverse":"selectiondialogselect";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogCommonLabelColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogcommonlabelinverse":"selectiondialogcommonlabel";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogItemTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogitemtextinverse":"selectiondialogitemtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogItemSelectedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogitemselectedtextinverse":"selectiondialogitemselectedtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogItemBackgroundColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogitembackgroundinverse":"selectiondialogitembackground";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::selectionDialogItemSelectedBackgroundColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "selectiondialogitemselectedbackgroundinverse":"selectiondialogitemselectedbackground";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::listTitleColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "listtitleinverse":"listtitle";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::listTitlePressedColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "listtitlepressedinverse":"listtitlepressed";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::listSubTitleColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "listsubtitleinverse":"listsubtitle";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::listSubTitlePressedColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "listsubtitlepressedinverse":"listsubtitlepressed";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::negitiveButtonTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "negitivebuttontextinverse":"negitivebuttontext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::positiveButtonTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "positivebuttontextinverse":"positivebuttontext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::tabButtonTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "tabbuttontextinverse":"tabbuttontext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::tabButtonPressedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "tabbuttonpressedtextinverse":"tabbuttonpressedtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::tabButtonLatchedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "tabbuttonlatchedtextinverse":"tabbuttonlatchedtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::negitiveButtonPressedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "negitivebuttonpressedtextinverse":"negitivebuttonpressedtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::negitiveButtonLatchedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "negitivebuttonlatchedtextinverse":"negitivebuttonlatchedtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::positiveButtonPressedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "positivebuttonpressedtextinverse":"positivebuttonpressedtext";
    return d->mEngine->colorParameter(param);
}

QColor QmlThemeParams::positiveButtonLatchedTextColor() const
{
    Q_D(const QmlThemeParams);
    QString param = d->mInverted ? "positivebuttonlatchedtextinverse":"positivebuttonlatchedtext";
    return d->mEngine->colorParameter(param);
}





