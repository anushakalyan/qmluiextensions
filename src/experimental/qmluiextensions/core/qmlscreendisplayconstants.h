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

#ifndef QMLSCREENDISPLAYCONSTANTS_H
#define QMLSCREENDISPLAYCONSTANTS_H

#include <QtCore>
static const qreal CATEGORY_SMALL_LIMIT = 3.2;
static const qreal CATEGORY_MEDIUM_LIMIT = 4.5;
static const qreal CATEGORY_LARGE_LIMIT = 7.0;
static const qreal DENSITY_SMALL_LIMIT = 140.0;
static const qreal DENSITY_MEDIUM_LIMIT = 180.0;
static const qreal DENSITY_LARGE_LIMIT = 270.0;
static const qreal DEFAULT_TWIPS_PER_INCH = 1440.0;
static const qreal DEFAULT_DPI = 211.7;
#ifdef Q_OS_SYMBIAN
static const int DISPLAY_WIDTH = 360;
static const int DISPLAY_HEIGHT = 640;
#endif
#if defined HAVE_MEEGOGRAPHICSSYSTEM && defined HAVE_MEEGOTOUCH
#ifdef __ARMEL__
static const int DEFAULT_MEEGO_WIDTH = 854;
static const int DEFAULT_MEEGO_HEIGHT = 480;
#else
static const int DEFAULT_MEEGO_WIDTH = 480;
static const int DEFAULT_MEEGO_HEIGHT = 854;
#endif
#else
static const int DISPLAY_WIDTH = 0;
static const int DISPLAY_HEIGHT = 0;
#endif

#endif
