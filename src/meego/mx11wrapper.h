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

#ifndef MX11WRAPPER_H
#define MX11WRAPPER_H

#ifdef HAVE_XLIB
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#endif


// Namespace that wraps up some X11 calls
class QImage;
class QWindow;
namespace MX11Wrapper
{

#ifdef HAVE_XLIB
    
    Atom XInternAtom(Display *display, const char *atom_name, Bool only_if_exists);

    Status XGetWindowAttributes(Display *display, Window w,
                                XWindowAttributes *window_attributes_return);

    int XGetWindowProperty(Display *display, Window w, Atom property,
                           long long_offset, long long_length, Bool del,
                           Atom req_type, Atom *actual_type_return,
                           int *actual_format_return,
                           unsigned long *nitems_return, unsigned long *bytes_after_return,
                           unsigned char **prop_return);

    int XFree(void *data);

    XErrorHandler XSetErrorHandler(XErrorHandler handler);

    int XDefaultScreen(Display *display);

    int XChangeWindowAttributes(Display *display, Window w, unsigned long valuemask,
                                XSetWindowAttributes *attributes);
    Display* x11Display(QWindow *window = 0);
    QImage qimageFromXImage(XImage* xi);
 #endif
}

#endif // MX11WRAPPER_H
