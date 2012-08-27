#include <QApplication>
#include <QWidget>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include "qmlwindoweventhandler_x11.h"
#else
#include "../compat/meego/qmlwindoweventhandler_x11.h"
#endif
#include "mdeclarativescreen_bridge.h"

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
bool (*QmlXWindowEventHandler::origEventFilter)(void*, long int*) = NULL;
#endif
QmlXWindowEventHandler * QmlXWindowEventHandler::instance = NULL;

namespace
{
const char * MeeGoTouchWindowManagerName = "MCompositor";
const char * MeeGoTouchOrientationAngle = "_MEEGOTOUCH_ORIENTATION_ANGLE";
}

static int handleXError(Display *,XErrorEvent*)
{
    return 0;
}

QmlXWindowEventHandler::QmlXWindowEventHandler()
    :QmlWindowEventHandler()
    ,windowId(0)
{
    mSwipeSupport = meegoCompositor();
    QmlXWindowEventHandler::instance = this;
}

QmlXWindowEventHandler::~QmlXWindowEventHandler()
{
    if (qApp) {
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    qApp->setEventFilter(origEventFilter);
#else
    qApp->removeNativeEventFilter(this);
#endif
    }
}


void QmlXWindowEventHandler::handleXVisibilityEvent(XVisibilityEvent *xevent)
{
    Window winId = MX11Wrapper::effectiveWinId(xevent->window);
    if (xevent->window == winId) {
        switch (xevent->state) {
        case VisibilityFullyObscured:
            QmlWindowEventHandler::visibilityChangeEvent(false);
            break;
        case VisibilityUnobscured:
        case VisibilityPartiallyObscured:
            QmlWindowEventHandler::viewModeChangeEvent();
            QmlWindowEventHandler::visibilityChangeEvent(true);
            break;
        default:
            break;
        }
    }
}

void QmlXWindowEventHandler::handleXPropertyEvent(XPropertyEvent *xevent)
{
    // _MEEGOTOUCH_VISIBLE_IN_SWITCHER is set by Home Screen for
    // windows that are in the switcher and visible. Set/unset the
    // flag because we need to combine this information with X11's
    // visibility events.

    if (xevent->state == PropertyNewValue) {

        Atom           type;
        int            format;
        unsigned long  nItems;
        unsigned long  bytesAfter;
        unsigned char *data = NULL;

        static Atom switcherAtom = MX11Wrapper::XInternAtom(MX11Wrapper::x11Display(),
                                                            "_MEEGOTOUCH_VISIBLE_IN_SWITCHER", True);

        if (xevent->atom == switcherAtom) {
            // Read value of the property. Should be 1 or 0.
            if (MX11Wrapper::XGetWindowProperty(MX11Wrapper::x11Display(), xevent->window, switcherAtom,
                                                0, 1, False, XA_CARDINAL, &type, &format, &nItems,
                                                &bytesAfter, &data) == Success && data) {

                const bool visibleInSwitcher = *data;

                // Visible in switcher property was added
                // => window is visible as a thumbnail
                if (visibleInSwitcher) {
                    QmlWindowEventHandler::viewModeChangeEvent(QmlWindowState::Thumbnail);
                    QmlWindowEventHandler::visibilityChangeEvent(true);

                    // Visible in switcher property was removed and
                    // fullyObscured is already set => window is not
                    // visible
                } else if (!QmlWindowEventHandler::isVisible()) {
                    QmlWindowEventHandler::visibilityChangeEvent(false);

                    // Visible in switcher property was removed and
                    // fullyObscured is not set => window visible and fullsize
                } else {
                    QmlWindowEventHandler::viewModeChangeEvent();
                    QmlWindowEventHandler::visibilityChangeEvent(true);
                }

                MX11Wrapper::XFree(data);
            }
        }
    }
}

void QmlXWindowEventHandler::handleXFocusChangeEvent(XFocusChangeEvent *xevent)
{
    Window winId = MX11Wrapper::effectiveWinId(xevent->window);

    if (xevent->window == winId) {
        if (xevent->mode == NotifyNormal) {
            if (xevent->type == FocusIn) {
                if (!windowActivated()) {
                    MX11Wrapper::appendEventMask(winId);
                }
                QmlWindowEventHandler::focusChangeEvent(QmlWindowEventHandler::FEFocusIn);
            } else {
                QmlWindowEventHandler::focusChangeEvent(QmlWindowEventHandler::FEFocusOut);
            }
        }
    }
}

// This writes the orientation angle of into the X11 window property,
// which makes OS dialogs coming on top follow the app orientation
void QmlXWindowEventHandler::writeX11OrientationAngleProperty()
{
    if (!windowId)
        return;
    Display *display = MX11Wrapper::x11Display();

    if (!display)
        return;
    int angle = MDeclarativeScreen::instance()->rotation();
    Atom orientationAngleAtom = XInternAtom(display, MeeGoTouchOrientationAngle, False);

    XChangeProperty(display, windowId, orientationAngleAtom, XA_CARDINAL, 32,
                    PropModeReplace, (unsigned char*)&angle, 1);
}

void QmlXWindowEventHandler::updateWindowOrientationAngle()
{
    writeX11OrientationAngleProperty();
}

bool QmlXWindowEventHandler::isMeeGoWindowManagerRunning()
{
    bool retValue = false;

    Display       *dpy = MX11Wrapper::x11Display();
    Window         rootw = RootWindow(dpy, XDefaultScreen(dpy));
    Atom           wmSupportAtom = MX11Wrapper::XInternAtom(dpy, "_NET_SUPPORTING_WM_CHECK", False);
    Atom           type;
    int            format;
    unsigned long  numItems;
    unsigned long  bytesAfter;
    unsigned char *data = 0;

    if (MX11Wrapper::XGetWindowProperty(dpy, rootw, wmSupportAtom, 0, 1, False, XA_WINDOW,
                                        &type, &format, &numItems, &bytesAfter, &data) == Success) {
        if (data) {

            Window wid = *(reinterpret_cast<Window *>(data));
            MX11Wrapper::XFree(data);
            data = 0;

            Atom wmNameAtom = MX11Wrapper::XInternAtom(dpy, "WM_NAME", False);

            // Set error handler because window wid we got might not exist and
            // the following name query would fail.
            int (*previousHandler)(Display *, XErrorEvent *) = MX11Wrapper::XSetErrorHandler(handleXError);

            if (MX11Wrapper::XGetWindowProperty(dpy, wid, wmNameAtom, 0, 16, False, XA_STRING,
                                                &type, &format, &numItems, &bytesAfter, &data) == Success) {
                if (data) {
                    if (strcmp(reinterpret_cast<const char *>(data), MeeGoTouchWindowManagerName) == 0) {
                        retValue = true;
                    }

                    XFree(data);
                    data = 0;
                }
            }

            MX11Wrapper::XSetErrorHandler(previousHandler);
        }
    }

    return retValue;
}

bool QmlXWindowEventHandler::meegoCompositor()
{
    // Check if we are using MeegoCompositor.
    static const bool usingMeego = isMeeGoWindowManagerRunning();
    return usingMeego;
}

bool QmlXWindowEventHandler::platformSupportsSwipe() const
{
    return mSwipeSupport;
}

bool QmlXWindowEventHandler::enableSupportForSwipe(bool enabled)
{
    if (platformSupportsSwipe() && mSwipeSupport != enabled) {
        QWidget * activeWindow = QApplication::activeWindow();
        if(!activeWindow) {
            return false;
        }
        Display *dpy = MX11Wrapper::x11Display();
        Window w = activeWindow->effectiveWinId();

        unsigned long val = (enabled) ? 0 : 1;

        Atom atom = XInternAtom(dpy, "_MEEGOTOUCH_CANNOT_MINIMIZE", false);
        if (!atom) {
            qWarning("Unable to obtain _MEEGOTOUCH_CANNOT_MINIMIZE. This example will only work "
                     "with the MeeGo Compositor!");
            return false;
        }

        XChangeProperty (dpy,
                         w,
                         atom,
                         XA_CARDINAL,
                         32,
                         PropModeReplace,
                         reinterpret_cast<unsigned char *>(&val),
                         1);
        mSwipeSupport = enabled;
        return true;
    }
    return false;
}

bool QmlXWindowEventHandler::handlePlatformEvent(void *message, long int *result)
{
    Q_UNUSED(result);
    XEvent *event = reinterpret_cast<XEvent*>(message);
    if (!instance->meegoCompositor() && event->type == VisibilityNotify) {
        XVisibilityEvent *xevent = reinterpret_cast<XVisibilityEvent *>(event);
        instance->handleXVisibilityEvent(xevent);
        return false;

    } else if (instance->meegoCompositor() && event->type == PropertyNotify) {
        XPropertyEvent *xevent = reinterpret_cast<XPropertyEvent *>(event);
        instance->handleXPropertyEvent(xevent);
        return false;

    } else if (event->type == FocusIn || event->type == FocusOut) {
        XFocusChangeEvent *xevent = reinterpret_cast<XFocusChangeEvent *>(event);
        instance->handleXFocusChangeEvent(xevent);
        return false;
    } else if (event->type == MapNotify) {
        XMapEvent * xevent = (XMapEvent*) event;
        instance->windowId = xevent->window;
        instance->writeX11OrientationAngleProperty();
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    } else if (origEventFilter)
        return origEventFilter(message, result);
#else
    }
#endif
    return false;
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
bool QmlXWindowEventHandler::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
   Q_UNUSED(eventType);
   return handlePlatformEvent(message,result);
}
#endif

void QmlXWindowEventHandler::installFilter()
{
    if (qApp) {
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
        origEventFilter = qApp->setEventFilter(handlePlatformEvent);
#else
        qApp->installNativeEventFilter(this);
#endif
    }
}
