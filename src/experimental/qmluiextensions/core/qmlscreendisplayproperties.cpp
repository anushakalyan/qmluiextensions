#include <QApplication>
#include "qmlscreendisplayconstants.h"
#include "qmlscreendisplayproperties.h"
#ifdef Q_OS_SYMBIAN
#include <aknappui.h>
#include <hal.h>
#include <featmgr.h>
#endif
#if defined HAVE_XLIB || defined Q_WS_X11
// These includes conflict with some of Qt's types, so should be kept last
#include "mx11wrapper.h"
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
# include <QScreen>
#else
#include <QDesktopWidget>
#endif

#undef Bool

int QmlScreenDimensions::displayWidth()
{
    int width = DISPLAY_WIDTH;
    if (!width) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        QScreen* screen = QGuiApplication::primaryScreen();
        width = screen->size().width();
#else
        width = QApplication::desktop()->screenGeometry().width();
#endif
    }
    return width;
}

int QmlScreenDimensions::displayHeight()
{
    int height = DISPLAY_HEIGHT;
    if (!height) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        QScreen* screen = QGuiApplication::primaryScreen();
        height = screen->size().height();
#else
        height = QApplication::desktop()->screenGeometry().height();
#endif
    }
    return height;
}

QSize QmlScreenDimensions::displaySize()
{
    QSize size;
#ifdef Q_OS_SYMBIAN
#ifndef __WINS__
    int pixelsX(0);
    int pixelsY(0);

    if (HAL::Get(HALData::EDisplayXPixels, pixelsX) == KErrNone
            && HAL::Get(HALData::EDisplayYPixels, pixelsY) == KErrNone) {
        size = QSize(pixelsX, pixelsY);
    }
#endif
#endif
    if (!size.isValid())
        size = QSize(displayWidth(), displayHeight());
    return size;
}
qreal QmlScreenDimensions::dpi()
{
    static qreal dpi = 0;
    if (!dpi) {
#ifdef Q_OS_SYMBIAN
#ifndef __WINS__
        int twipsX(0);
        int twipsY(0);
        int pixelsX(0);
        int pixelsY(0);

        if (HAL::Get(HALData::EDisplayXTwips, twipsX) == KErrNone
                && HAL::Get(HALData::EDisplayYTwips, twipsY) == KErrNone
                && HAL::Get(HALData::EDisplayXPixels, pixelsX) == KErrNone
                && HAL::Get(HALData::EDisplayYPixels, pixelsY) == KErrNone) {
            dpi = 0.5 * ((pixelsX / (twipsX / DEFAULT_TWIPS_PER_INCH)) +
                         (pixelsY / (twipsY / DEFAULT_TWIPS_PER_INCH)));
        }
#elif defined(Q_WS_SIMULATOR)
        int width = displayWidth();
        int height = displayHeight();
        qreal physicalDisplaySize = 0.0;

        // Guessing the display size because we have no means to figure it out in Qt Simulator
        if (width*height == 640*360)
            physicalDisplaySize = 3.5;
        else if (width*height == 640*480)
            physicalDisplaySize = 2.46;
        else if (width*height == 320*240)
            physicalDisplaySize = 2.8;
        else if (width*height == 800*480)
            physicalDisplaySize = 3.5;
        else
            physicalDisplaySize = 3.5;
        qreal width_r = width;
        qreal height_r = height;
        dpi = sqrt(width_r*width_r + height_r*height_r) / physicalDisplaySize;
#endif
#endif

#if defined(HAVE_XLIB) || defined (Q_WS_X11)
#if defined(HAVE_XRANDR)
        int physicalHeight = MX11Wrapper::physicalHeight();
        if(physicalHeight) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        QScreen* screen = QGuiApplication::primaryScreen();
        dpi = screen->size().height() / (physicalHeight / 25.4);
#else
        dpi = QDesktopWidget().screenGeometry().height() / (physicalHeight / 25.4);
#endif
        }
#endif
#endif
        if (!dpi) {//assumption is of square pixels
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
            QScreen* screen = QGuiApplication::primaryScreen();
            dpi = screen->physicalDotsPerInchX();
#else
            dpi = QDesktopWidget().physicalDpiX();
#endif
        }
    }
    return dpi;
}

QmlScreenDimensions::DisplayCategory QmlScreenDimensions::displayCategory()
{
    const int w = displayWidth();
    const int h = displayHeight();

    const qreal diagonal = qSqrt(static_cast<qreal>(w * w + h * h)) / dpi();

    if (diagonal < CATEGORY_SMALL_LIMIT)
        return Small;
    else if (diagonal < CATEGORY_MEDIUM_LIMIT)
        return Normal;
    else if (diagonal < CATEGORY_LARGE_LIMIT)
        return Large;
    else
        return  ExtraLarge;
}

QmlScreenDimensions::Density QmlScreenDimensions::density()
{
    if (dpi() < DENSITY_SMALL_LIMIT)
        return Low;
    else if (dpi() < DENSITY_MEDIUM_LIMIT)
        return Medium;
    else if (dpi() < DENSITY_LARGE_LIMIT)
        return High;
    else
        return ExtraHigh;
}
