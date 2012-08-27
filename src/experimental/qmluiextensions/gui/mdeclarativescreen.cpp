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

#include <QApplication>
#include <QDebug>
#include <QDeclarativeItem>
#include <QWindowStateChangeEvent>
#include <QDesktopWidget>
#include <math.h>

#ifdef HAVE_CONTEXTSUBSCRIBER
# include "contextproperty.h"
# include "contextpropertyinfo.h"
# include "mservicelistener.h"
#endif

#if defined HAVE_XLIB || defined Q_WS_X11
  // These includes conflict with some of Qt's types, so should be kept last
# include <X11/Xatom.h>
# include <X11/Xlib.h>
#include "mx11wrapper.h"
#endif
# if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#  include <QtQuick/qquickitem.h>
# endif
# include "mwindowstate_bridge.h"
# include "mdeclarativescreen_bridge.h"
#include "mdeclarativeinputcontext_bridge.h"
#if defined(Q_WS_X11)
#  include <QX11Info>
#endif

#ifdef HAVE_XRANDR
#include <X11/extensions/Xrandr.h>
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
# include <QWindow>
# include <QScreen>
#endif
#include "../core/qmlscreendisplayproperties.h"
#include "../core/qmlwindowstate_p.h"

#undef Bool

class MDeclarativeScreenPrivate
{
public:
    MDeclarativeScreenPrivate(MDeclarativeScreen *qq);
    ~MDeclarativeScreenPrivate();

    void updateOrientationAngleProperty();
    void initContextSubscriber();

    void _q_isCoveredChanged();
    void _q_updateOrientationAngle();
    void _q_updateIsTvConnected();
    void _q_windowAnimationChanged();

    void updateScreenSize();

    qreal dpi() const;
    int rotation() const;

    MDeclarativeScreen::Orientation physicalOrientation() const;

    MDeclarativeScreen *q;

    MDeclarativeScreen::Orientation orientation;
    MDeclarativeScreen::Orientation finalOrientation;
    MDeclarativeScreen::Orientations allowedOrientations;
    MDeclarativeScreen::Orientations allowedOrientationsBackup;
    MDeclarativeScreen::Direction rotationDirection;

    bool isCovered;
    bool keyboardOpen;
    bool isTvConnected;

    QPointer<QWidget> topLevelWidget;

    QSize displaySize;
    QSize screenSize;

    void setMinimized(bool);
    bool isMinimized() const;
    bool isRemoteScreenPresent() const;
    QString topEdgeValue() const;

    MDeclarativeScreen::Orientations physicalDisplayOrientation() const { return _physicalDisplayOrientation; }

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    QWeakPointer<QWindow> window;
#endif

#ifdef HAVE_CONTEXTSUBSCRIBER
    ContextProperty topEdgeProperty;
    ContextProperty remoteTopEdgeProperty;
    ContextProperty isCoveredProperty;
    ContextProperty keyboardOpenProperty;
    ContextProperty videoRouteProperty;
    MServiceListener remoteTopEdgeListener;
#endif
private:
    void initPhysicalDisplayOrientation();

private:
    bool minimized;
    MDeclarativeScreen::Orientations _physicalDisplayOrientation;
};

static MDeclarativeScreen *self = 0;
static MDeclarativeScreenPrivate *gScreenPrivate = 0;

MDeclarativeScreen* MDeclarativeScreen::instance()
{
    if (!self)
        self = new MDeclarativeScreen();
    return self;
}


MDeclarativeScreenPrivate::MDeclarativeScreenPrivate(MDeclarativeScreen *qq)
    : q(qq)
#ifdef __ARMEL__
    , orientation(MDeclarativeScreen::Landscape)
    , finalOrientation(MDeclarativeScreen::Landscape)
#else
    , orientation(MDeclarativeScreen::Portrait)
    , finalOrientation(MDeclarativeScreen::Portrait)
#endif
    , allowedOrientations(MDeclarativeScreen::Landscape | MDeclarativeScreen::Portrait)
    , rotationDirection(MDeclarativeScreen::NoDirection)
    , isCovered(false)
    , keyboardOpen(false)
    , isTvConnected(false)
    , topLevelWidget(0)
#ifdef HAVE_CONTEXTSUBSCRIBER
    , topEdgeProperty("Screen.TopEdge")
    , remoteTopEdgeProperty("RemoteScreen.TopEdge")
    , isCoveredProperty("Screen.IsCovered")
    , keyboardOpenProperty("/maemo/InternalKeyboard/Open")
    , videoRouteProperty("com.nokia.policy.video_route")
    , remoteTopEdgeListener(remoteTopEdgeProperty.info()->providerDBusType()
    , remoteTopEdgeProperty.info()->providerDBusName())
#endif
    , minimized(false)
{
    displaySize = QmlScreenDimensions::displaySize();
    //Q_ASSERT(gScreenPrivate == 0);
    gScreenPrivate = this;
    //syncup possible physicaldisplay orientation && screen orientation when app has just started
    if (displaySize.height() < displaySize.width()) {
        orientation = MDeclarativeScreen::Landscape;
        finalOrientation = MDeclarativeScreen::Landscape;
    }
    initPhysicalDisplayOrientation();
}

MDeclarativeScreenPrivate::~MDeclarativeScreenPrivate()
{
}

void MDeclarativeScreenPrivate::initPhysicalDisplayOrientation()
{
    if(displaySize.isValid()) {
        if(displaySize.height() > displaySize.width()) {
            _physicalDisplayOrientation = MDeclarativeScreen::Portrait;
            _physicalDisplayOrientation |= MDeclarativeScreen::PortraitInverted;
        } else {
            _physicalDisplayOrientation = MDeclarativeScreen::Landscape;
            _physicalDisplayOrientation |= MDeclarativeScreen::LandscapeInverted;
        }
        updateScreenSize();
    }
}

void MDeclarativeScreenPrivate::initContextSubscriber()
{
#ifdef HAVE_CONTEXTSUBSCRIBER
    //waiting for properties to synchronize
    topEdgeProperty.waitForSubscription();
    isCoveredProperty.waitForSubscription();
    keyboardOpenProperty.waitForSubscription();
    videoRouteProperty.waitForSubscription();
    remoteTopEdgeListener.startListening(true);

    QObject::connect(&topEdgeProperty, SIGNAL(valueChanged()),
                     q, SLOT(_q_updateOrientationAngle()));
    QObject::connect(&remoteTopEdgeProperty, SIGNAL(valueChanged()),
                     q, SLOT(_q_updateOrientationAngle()));
    QObject::connect(&keyboardOpenProperty, SIGNAL(valueChanged()),
                     q, SLOT(_q_updateOrientationAngle()));
    QObject::connect(&isCoveredProperty, SIGNAL(valueChanged()),
                     q, SLOT(_q_isCoveredChanged()));
    QObject::connect(&videoRouteProperty, SIGNAL(valueChanged()),
                     q, SLOT(_q_updateIsTvConnected()));
    QObject::connect(&remoteTopEdgeListener, SIGNAL(nameAppeared()),
                     q, SLOT(_q_updateOrientationAngle()));
    QObject::connect(&remoteTopEdgeListener, SIGNAL(nameDisappeared()),
                     q, SLOT(_q_updateOrientationAngle()));
#endif
    //initiating the variables to current orientation
#ifdef __ARMEL__
    _q_updateOrientationAngle();
#endif
    _q_isCoveredChanged();

    updateOrientationAngleProperty();
    _q_updateIsTvConnected();
    QObject::connect(QmlWindowState::instance(), SIGNAL(animatingChanged()),
                     q, SLOT(_q_windowAnimationChanged()));
}

void MDeclarativeScreenPrivate::updateScreenSize() {
    // Update screen width / height properties
    if(orientation & physicalDisplayOrientation()) {
        screenSize.setWidth(displaySize.width());
        screenSize.setHeight(displaySize.height());
    } else {
        screenSize.setWidth(displaySize.height());
        screenSize.setHeight(displaySize.width());
    }
    emit q->platformWidthChanged();
    emit q->platformHeightChanged();
}

void MDeclarativeScreenPrivate::updateOrientationAngleProperty()
{
    //hint window manager in case it needs to display
    //additional content like popups, dialogs, status bars, or similar
    //in relation to the window.
    QmlWindowState::instance()->updateWindowOrientationAngle();
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    if (!window)
        return;

    Qt::ScreenOrientation o = Qt::PrimaryOrientation;
    switch (q->rotation()) {
    case 0: o = Qt::LandscapeOrientation; break;
    case 90: o = Qt::InvertedPortraitOrientation; break;
    case 180: o = Qt::InvertedLandscapeOrientation; break;
    case 270: o = Qt::PortraitOrientation; break;
    default:
        qCritical() << "MDeclarativeScreen has invalid orientation set.";
    }
    if (o != Qt::PrimaryOrientation) {
        window.data()->reportContentOrientationChange(o);
    }
#endif
}

void MDeclarativeScreenPrivate::_q_isCoveredChanged()
{
#ifdef HAVE_CONTEXTSUBSCRIBER
    bool covered = isCoveredProperty.value().toBool();

    if (isCovered != covered) {
        qDebug() << "MDeclarativeScreenPrivate" << "Covered:" << covered;

        isCovered = covered;
        emit q->coveredChanged();
    }
#endif
}

void MDeclarativeScreenPrivate::_q_updateIsTvConnected()
{
#ifdef HAVE_CONTEXTSUBSCRIBER
    QString value = videoRouteProperty.value().toString();

    isTvConnected = (value == "tvout" ||
                     value == "builtinandtvout");
    _q_updateOrientationAngle();
#endif
}

qreal MDeclarativeScreenPrivate::dpi() const
{
    static qreal dpi = QmlScreenDimensions::dpi();
    return dpi;
}

int MDeclarativeScreenPrivate::rotation() const
{
    int angle = 0;

    if(_physicalDisplayOrientation & MDeclarativeScreen::Landscape) {
        switch (orientation) {
        case MDeclarativeScreen::Landscape:
            angle = 0;
            break;
        case MDeclarativeScreen::Portrait:
        case MDeclarativeScreen::Default:  //handle default as portrait
            angle = 270;
            break;
        case MDeclarativeScreen::LandscapeInverted:
            angle = 180;
            break;
        case MDeclarativeScreen::PortraitInverted:
            angle = 90;
            break;
        default:
            qCritical() << "MDeclarativeScreen hast invalid orientation set.";
        }
    } else {
        switch (orientation) {
        case MDeclarativeScreen::Landscape:
            angle = 90;
            break;
        case MDeclarativeScreen::Portrait:
        case MDeclarativeScreen::Default:  //handle default as portrait
            angle = 0;
            break;
        case MDeclarativeScreen::LandscapeInverted:
            angle = 270;
            break;
        case MDeclarativeScreen::PortraitInverted:
            angle = 180;
            break;
        default:
            qCritical() << "MDeclarativeScreen hast invalid orientation set.";
        }
    }

    return angle;
}

MDeclarativeScreen::Orientation MDeclarativeScreenPrivate::physicalOrientation() const {
    MDeclarativeScreen::Orientation o = MDeclarativeScreen::Default;
#ifdef HAVE_CONTEXTSUBSCRIBER
    QString topEdge = topEdgeValue();

    if (topEdge == "top") {
        o = MDeclarativeScreen::Landscape;
    } else if (topEdge == "left") {
        o = MDeclarativeScreen::Portrait;
    } else if (topEdge == "right") {
        o = MDeclarativeScreen::PortraitInverted;
    } else if (topEdge == "bottom") {
        o = MDeclarativeScreen::LandscapeInverted;
    }
#endif
    return o;
}

void MDeclarativeScreenPrivate::_q_updateOrientationAngle()
{
    MDeclarativeScreen::Orientation newOrientation = MDeclarativeScreen::Default;

#ifdef HAVE_CONTEXTSUBSCRIBER
    QString edge = topEdgeValue();
    bool open = keyboardOpenProperty.value().toBool();

    //HW Keyboard open or TV connected causes a switch to landscape, but only if this is allowed
    if ((open || isTvConnected) && allowedOrientations & MDeclarativeScreen::Landscape) {
        newOrientation = MDeclarativeScreen::Landscape;
    } else if (edge == "top" && (allowedOrientations & MDeclarativeScreen::Landscape)) {
        newOrientation = MDeclarativeScreen::Landscape;
    } else if (edge == "left" && (allowedOrientations & MDeclarativeScreen::Portrait)) {
        newOrientation = MDeclarativeScreen::Portrait;
    } else if (edge == "right" && (allowedOrientations & MDeclarativeScreen::PortraitInverted)) {
        newOrientation = MDeclarativeScreen::PortraitInverted;
    } else if (edge == "bottom" && (allowedOrientations & MDeclarativeScreen::LandscapeInverted)) {
        newOrientation = MDeclarativeScreen::LandscapeInverted;
    }

    if (open != keyboardOpen) {
        keyboardOpen = open;
        emit q->keyboardOpenChanged();
    }
#elif QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    QScreen* screen = QGuiApplication::primaryScreen();
    if (window)
        screen = window.data()->screen();
    Qt::ScreenOrientation orientation = screen->orientation();
    switch (orientation) {
    case Qt::LandscapeOrientation:
        if (allowedOrientations & MDeclarativeScreen::Landscape)
            newOrientation = MDeclarativeScreen::Landscape;
        break;
    case Qt::PortraitOrientation:
        if (allowedOrientations & MDeclarativeScreen::Portrait)
            newOrientation = MDeclarativeScreen::Portrait;
        break;
    case Qt::InvertedLandscapeOrientation:
        if (allowedOrientations & MDeclarativeScreen::LandscapeInverted)
            newOrientation = MDeclarativeScreen::LandscapeInverted;
        break;
    case Qt::InvertedPortraitOrientation:
        if (allowedOrientations & MDeclarativeScreen::PortraitInverted)
            newOrientation = MDeclarativeScreen::PortraitInverted;
        break;
    case Qt::PrimaryOrientation: break;
    }
#endif

    //only set the new orientation if it is a valid one
    if(newOrientation != MDeclarativeScreen::Default) {
        q->setOrientation(newOrientation);
    }
}

void MDeclarativeScreenPrivate::_q_windowAnimationChanged()
{
    if (!QmlWindowState::instance()->animating() && finalOrientation != orientation)
        q->setOrientation(finalOrientation);
}

void MDeclarativeScreenPrivate::setMinimized(bool m) {
    if(minimized == m)
        return;

    minimized = m;
    emit q->minimizedChanged();
}

bool MDeclarativeScreenPrivate::isMinimized() const {
    return minimized;
}

bool MDeclarativeScreenPrivate::isRemoteScreenPresent() const {
    bool present = false;
#ifdef HAVE_CONTEXTSUBSCRIBER
    QString remoteTopEdge = remoteTopEdgeProperty.value().toString();
    bool remoteTopEdgePresent = (remoteTopEdgeListener.isServicePresent() == MServiceListener::Present);
    present = remoteTopEdgePresent && !remoteTopEdge.isEmpty();
#endif
    return present;
}

QString MDeclarativeScreenPrivate::topEdgeValue() const {
    QString top; // Empty string simulates MDeclarativeScreen::Default orientation
#ifdef HAVE_CONTEXTSUBSCRIBER
    QString topEdge = topEdgeProperty.value().toString();
    QString remoteTopEdge = remoteTopEdgeProperty.value().toString();
    top = isRemoteScreenPresent() ? remoteTopEdge : topEdge;
#endif
    return top;
}

MDeclarativeScreen::MDeclarativeScreen(QObject *parent)
        : QObject(parent),
        d(new MDeclarativeScreenPrivate(this))
{
    d->initContextSubscriber();
    qApp->installEventFilter(this);
    emit physicalDisplayChanged();
}

MDeclarativeScreen::~MDeclarativeScreen()
{
    delete d;
}

bool MDeclarativeScreen::eventFilter(QObject *o, QEvent *e) {
    if(e->type() == QEvent::WindowStateChange) {
        qDebug()<<"window state change from screen";
        d->topLevelWidget = qobject_cast<QWidget*>(o);
        bool haveWindow = false;
        if(d->topLevelWidget && d->topLevelWidget->parent() == NULL) { //it's a toplevelwidget
            d->setMinimized(d->topLevelWidget->windowState() & Qt::WindowMinimized);
            haveWindow = true;
        } else {
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
            QWindow* w = qobject_cast<QWindow*>(o);
            if (!d->window) {
                d->window = w;
                connect(w->screen(), SIGNAL(orientationChanged(Qt::ScreenOrientation)),
                        this, SLOT(_q_updateOrientationAngle()));
            }
            if (d->window) {
                d->setMinimized(d->window.data()->windowState() & Qt::WindowMinimized);
                haveWindow = true;
            }
#else
            qCritical() << "State change event from foreign window";
#endif
        }

        if (haveWindow) {
            if(d->isMinimized()) {
                d->allowedOrientationsBackup = d->allowedOrientations;

                //set allowedOrientations manually, because setAllowedOrientations() will not work while minimized
                //minimized apps are forced to portrait or landscape based on maximized state
                if (!d->allowedOrientationsBackup || (d->allowedOrientationsBackup & Portrait) || 
                   (d->allowedOrientationsBackup & PortraitInverted)) {
                    d->allowedOrientations = Portrait;
                    setOrientation(Portrait);
                } else {
                    d->allowedOrientations = Landscape;
                    setOrientation(Landscape);
                }
            } else {
                if(d->allowedOrientationsBackup != Default) {
                    setAllowedOrientations(d->allowedOrientationsBackup);
                    //if the current sensor's value is allowed, switch to it

                    if(d->physicalOrientation() & allowedOrientations())
                        setOrientation(d->physicalOrientation());
                }
            }
        }
    }
    return QObject::eventFilter(o, e);
}

MDeclarativeScreen::Orientations MDeclarativeScreen::platformPhysicalDisplayOrientation() const
{
    return d->physicalDisplayOrientation();
}

void MDeclarativeScreen::setOrientation(Orientation o)
{
    d->finalOrientation = o;
    MDeclarativeScreen::Direction oldDirection = d->rotationDirection;
    if (d->orientation == o || QmlWindowState::instance()->animating())
        return;

    if ( (d->orientation == MDeclarativeScreen::LandscapeInverted && o == MDeclarativeScreen::Portrait) ||
         (d->orientation == MDeclarativeScreen::PortraitInverted && o == MDeclarativeScreen::LandscapeInverted) ||
         (d->orientation == MDeclarativeScreen::Landscape && o == MDeclarativeScreen::PortraitInverted) ||
         (d->orientation == MDeclarativeScreen::Portrait && o == MDeclarativeScreen::Landscape) ) {
         d->rotationDirection = MDeclarativeScreen::CounterClockwise;
    }
    else {
         d->rotationDirection = MDeclarativeScreen::Clockwise;
    }
    if (oldDirection != d->rotationDirection)
        emit rotationDirectionChanged();

    Orientation newOrientation = Default;
    //if keyboard is open always set landscape and ignore allowed orientations
#ifdef HAVE_CONTEXTSUBSCRIBER
    if(d->keyboardOpenProperty.value().toBool()) {
        newOrientation = Landscape;
    } else {
#endif
        if (!(d->allowedOrientations & o))
            return;
        newOrientation = o;
#ifdef HAVE_CONTEXTSUBSCRIBER
    }
#endif
    qDebug()<<"setting new orientation"<<newOrientation;
    d->orientation = newOrientation;
    d->updateOrientationAngleProperty();

    d->updateScreenSize();


    emit widthChanged();
    emit heightChanged();

    MDeclarativeInputContext::setKeyboardOrientation(o);
    emit currentOrientationChanged();
}

MDeclarativeScreen::Orientation MDeclarativeScreen::currentOrientation() const
{
    return d->orientation;
}

void MDeclarativeScreen::setAllowedOrientations(Orientations orientation) {
    if (d->allowedOrientations == orientation
        || d->isMinimized()) //fixed portrait when minimized, no change possible!
        return;

    d->allowedOrientations = orientation;

    // Check if physical orientation fits allowed orientations
    if(d->physicalOrientation() != d->orientation) {
        if(d->physicalOrientation() & d->allowedOrientations) {
            setOrientation(d->physicalOrientation());
        }
    }

    // Check if current orientation still fits allowed
    if(!(d->orientation & d->allowedOrientations)) {
        if(d->allowedOrientations & MDeclarativeScreen::Portrait) {
            setOrientation(MDeclarativeScreen::Portrait);
            return;
        } else if(d->allowedOrientations & MDeclarativeScreen::Landscape) {
            setOrientation(MDeclarativeScreen::Landscape);
            return;
        } else if(d->allowedOrientations & MDeclarativeScreen::LandscapeInverted) {
            setOrientation(MDeclarativeScreen::LandscapeInverted);
            return;
        } else if(d->allowedOrientations & MDeclarativeScreen::PortraitInverted) {
            setOrientation(MDeclarativeScreen::PortraitInverted);
            return;
        }
    }
    emit allowedOrientationsChanged();
}

MDeclarativeScreen::Orientations MDeclarativeScreen::allowedOrientations() const {
    return d->allowedOrientations;
}

QString MDeclarativeScreen::orientationString() const
{
    const char *s = 0;
    switch (d->orientation) {
    case Portrait:
        s = "Portrait";
        break;
    case PortraitInverted:
        s = "PortraitInverted";
        break;
    case Landscape:
        s = "Landscape";
        break;
    case LandscapeInverted:
        s = "LandscapeInverted";
        break;
    default:
        qCritical() << "MDeclarativeScreen has invalid orientation set.";
        break;
    }
    return QString::fromLatin1(s);
}

int MDeclarativeScreen::rotation() const
{
    return d->rotation();
}

MDeclarativeScreen::Direction MDeclarativeScreen::rotationDirection() const
{
    return d->rotationDirection;
}

bool MDeclarativeScreen::isCovered() const
{
    return d->isCovered;
}

bool MDeclarativeScreen::isKeyboardOpen() const
{
    return d->keyboardOpen;
}

bool MDeclarativeScreen::isMinimized() const
{
    return d->isMinimized();
}

void MDeclarativeScreen::setMinimized(bool minimized)
{
    if(minimized == d->isMinimized())
        return;

    if(d->topLevelWidget) {
        d->topLevelWidget->setWindowState(minimized ? Qt::WindowMinimized : Qt::WindowMaximized);
        d->setMinimized(minimized);
    } else {
        qCritical() << "No top level widget set";
    }
}

int MDeclarativeScreen::width() const
{
#ifdef USE_DEPRECATED_SCREEN_WIDTH_HEIGHT
    qWarning() << "The semantics of screen.width property is deprecated, see QTCOMPONENTS-521. Please use screen.displayWidth to query native screen width.";
    return d->displaySize.width();
#else
    //Enable these after applications have been changed
    return d->screenSize.width();
#endif
}

int MDeclarativeScreen::height() const
{
#ifdef USE_DEPRECATED_SCREEN_WIDTH_HEIGHT
    qWarning() << "The semantics of screen.height property is deprecated, see QTCOMPONENTS-521. Please use screen.displayHeight to query native screen height.";
    return d->displaySize.height();
#else
    // Enable these after applications have been changed
    return d->screenSize.height();
#endif
}

int MDeclarativeScreen::platformWidth() const
{
    return d->screenSize.width();
}

int MDeclarativeScreen::platformHeight() const
{
    return d->screenSize.height();
}


int MDeclarativeScreen::displayWidth() const
{
    return d->displaySize.width();
}

int MDeclarativeScreen::displayHeight() const
{
    return d->displaySize.height();
}

/*MWindowState * MDeclarativeScreen::windowState() const
{
    qWarning() << "Warning: screen.windowState() is deprecated, use platformWindow property instead";
    return MWindowState::instance();
}*/

int MDeclarativeScreen::dpi() const {
    return d->dpi();
}

MDeclarativeScreen::DisplayCategory MDeclarativeScreen::displayCategory() const {
        return static_cast<MDeclarativeScreen::DisplayCategory>(QmlScreenDimensions::displayCategory());
}

MDeclarativeScreen::Density MDeclarativeScreen::density() const {
    return static_cast<MDeclarativeScreen::Density>(QmlScreenDimensions::density());
}

# if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
void MDeclarativeScreen::updatePlatformStatusBarRect(QDeclarativeItem * statusBar)
#else
void MDeclarativeScreen::updatePlatformStatusBarRect(QQuickItem * statusBar)
#endif
{
    Q_UNUSED(statusBar);

#if defined HAVE_XLIB || defined Q_WS_X11
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QWidget * activeWindow = QApplication::activeWindow();
    if(!activeWindow) {
        foreach (QWidget *widget, QApplication::topLevelWidgets()) {
            if (widget->effectiveWinId() != 0 &&
                widget->windowType() == Qt::Window) {
                activeWindow = widget;
                break;
            } 
        }

        if (!activeWindow)
            return;
    }
#endif

    Display *dpy = MX11Wrapper::x11Display();
    if (!dpy)
        return;

    QRectF rect(statusBar->mapRectToScene(QRectF(qreal(0), qreal(0), qreal(statusBar->width()), qreal(statusBar->height()))));
    unsigned long data[4] = {0};

    if(statusBar->y() >= 0) {
        data[0] = 0;
        data[1] = 0;
        data[2] = rect.width();
        data[3] = rect.height();
    }

    Atom a = XInternAtom(dpy, "_MEEGOTOUCH_MSTATUSBAR_GEOMETRY", False);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
     if (!d->window) {
         return;
     }
    Window w = d->window.data()->winId();
#else
    Window w = activeWindow->effectiveWinId();
#endif

    if(data[3] == 0)
        XDeleteProperty(dpy, w, a);
    else
        XChangeProperty(dpy, w, a, XA_CARDINAL, 32, PropModeReplace, (unsigned char*)data, 4);
#endif
}

bool MDeclarativeScreen::allowSwipe() const
{
    return QmlWindowState::instance()->d_ptr->allowSwipe();
}

bool MDeclarativeScreen::isPortrait() const
{
    return platformHeight() > platformWidth();
}

bool MDeclarativeScreen::isDisplayLandscape() const {
    return platformPhysicalDisplayOrientation() & Landscape;
}

void MDeclarativeScreen::setAllowSwipe(bool enabled)
{
   if (QmlWindowState::instance()->d_ptr->setAllowSwipe(enabled))
       emit allowSwipeChanged();
}

#if defined HAVE_XLIB || defined Q_WS_X11
Display* MDeclarativeScreen::display(QDeclarativeItem* item) const
{
    QWindow* window = NULL;
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    window = gScreenPrivate->window.data();
    if (!window && item)
        window = item->canvas();
# else
    Q_UNUSED(item);
#endif
    return MX11Wrapper::x11Display(window);
}
#endif

#include "moc_mdeclarativescreen.cpp"
