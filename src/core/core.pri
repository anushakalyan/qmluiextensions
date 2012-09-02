HEADERS += \
    core/mdeclarativeimageprovider.h \
    core/minversemousearea.h \
    core/qmlscreendisplayproperties.h \
    core/qmlwindoweventhandler.h \
    core/qmlwindowstate.h \
    core/qmluiextensionsnamespace.h \
    core/qmlcommon.h \
    core/x/*.h

SOURCES += \
    core/mdeclarativeimageprovider.cpp \
    core/minversemousearea.cpp \
    core/qmlscreendisplayproperties.cpp \
    core/qmlwindoweventhandler.cpp \
    core/qmlwindowstate.cpp \
    core/x/*.cpp

contextsubscriber {
    DEFINES += HAVE_CONTEXTSUBSCRIBER
    INCLUDEPATH += /usr/include/contextsubscriber
    LIBS += -lcontextsubscriber
    SOURCES += mservicelistener.cpp
    HEADERS += mservicelistener.h
    # PKGCONFIG += contextsubscriber
}

greaterThan(QT_MAJOR_VERSION, 4) {
# Tweaks sources and headers for Qt5
QT += gui-private
HEADERS += \
    core/compat/qmlmousefilter.h
SOURCES += \
    core/compat/qmlmousefilter.cpp
}

!greaterThan(QT_MAJOR_VERSION, 4) {
HEADERS += \
    core/qmlmousefilter.h
SOURCES += \
    core/qmlmousefilter.cpp
}
