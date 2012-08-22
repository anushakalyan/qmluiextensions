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

# include <QtCore>
# include <QImage>
# if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
# include <QtGui/qpa/qplatformnativeinterface.h>
# include <QGuiApplication>
# else
# include <QX11Info>
# endif
#include "mx11wrapper.h"

#ifdef HAVE_XLIB

Atom MX11Wrapper::XInternAtom(Display *display, const char *atom_name, Bool only_if_exists)
{
    return ::XInternAtom(display, atom_name, only_if_exists);
}

Status MX11Wrapper::XGetWindowAttributes(Display *display, Window w,
                                         XWindowAttributes *window_attributes_return)
{
    return ::XGetWindowAttributes(display, w, window_attributes_return);
}

int MX11Wrapper::XGetWindowProperty(Display *display, Window w, Atom property,
                       long long_offset, long long_length, Bool del,
                       Atom req_type, Atom *actual_type_return,
                       int *actual_format_return,
                       unsigned long *nitems_return, unsigned long *bytes_after_return,
                       unsigned char **prop_return)
{
    return ::XGetWindowProperty(display, w, property, long_offset, long_length, del,
                                req_type, actual_type_return,
                                actual_format_return,
                                nitems_return, bytes_after_return,
                                prop_return);
}

int MX11Wrapper::XFree(void *data)
{
    return ::XFree(data);
}

XErrorHandler MX11Wrapper::XSetErrorHandler(XErrorHandler handler)
{
    return ::XSetErrorHandler(handler);
}

int MX11Wrapper::XDefaultScreen(Display *display)
{
    return ::XDefaultScreen(display);
}

int MX11Wrapper::XChangeWindowAttributes(Display *display, Window w, unsigned long valuemask,
                                         XSetWindowAttributes *attributes)
{
    return ::XChangeWindowAttributes(display, w, valuemask, attributes);
}

Display* MX11Wrapper::x11Display(QWindow *window)
{
    static Display* lastKnownDisplay = 0;
    if (!lastKnownDisplay) {
#if QT_VERSION >=QT_VERSION_CHECK(5, 0, 0)
        lastKnownDisplay = XOpenDisplay(0);
        QPlatformNativeInterface* iface = QGuiApplication::platformNativeInterface();
        lastKnownDisplay = (Display*)iface->nativeResourceForWindow("display",window);
#else
        Q_UNUSED(window);
        lastKnownDisplay = QX11Info::display();
#endif
     }
     return lastKnownDisplay;
 }

QImage MX11Wrapper::qimageFromXImage(XImage* xi)
{
    QImage::Format format = QImage::Format_ARGB32_Premultiplied;
    if (xi->depth == 24)
        format = QImage::Format_RGB32;
    else if (xi->depth == 16)
        format = QImage::Format_RGB16;

    QImage image = QImage(reinterpret_cast<uchar*>(xi->data), xi->width, xi->height, xi->bytes_per_line, format).copy();

    // we may have to swap the byte order
    if ((QSysInfo::ByteOrder == QSysInfo::LittleEndian && xi->byte_order == MSBFirst)
        || (QSysInfo::ByteOrder == QSysInfo::BigEndian && xi->byte_order == LSBFirst)) {

        for (int i = 0; i < image.height(); i++) {
            if (xi->depth == 16) {
                ushort* p = reinterpret_cast<ushort*>(image.scanLine(i));
                ushort* end = p + image.width();
                while (p < end) {
                    *p = ((*p << 8) & 0xff00) | ((*p >> 8) & 0x00ff);
                    p++;
                }
            } else {
                uint* p = reinterpret_cast<uint*>(image.scanLine(i));
                uint* end = p + image.width();
                while (p < end) {
                    *p = ((*p << 24) & 0xff000000) | ((*p << 8) & 0x00ff0000)
                         | ((*p >> 8) & 0x0000ff00) | ((*p >> 24) & 0x000000ff);
                    p++;
                }
            }
        }
    }

    // fix-up alpha channel
    if (format == QImage::Format_RGB32) {
        QRgb* p = reinterpret_cast<QRgb*>(image.bits());
        for (int y = 0; y < xi->height; ++y) {
            for (int x = 0; x < xi->width; ++x)
                p[x] |= 0xff000000;
            p += xi->bytes_per_line / 4;
        }
    }

    return image;
}
#endif // Q_WS_X11
