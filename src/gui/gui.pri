HEADERS += \
    gui/models/qrangemodel.h \
    gui/models/qrangemodel_p.h \
    gui/core/mdeclarativeimplicitsizeitem.h \
    gui/core/mdialogstatus.h \
    gui/core/mpageorientation.h \
    gui/core/mpagestatus.h \
    gui/core/mscrolldecoratorsizer.h \
    gui/core/mtoolbarvisibility.h \
    gui/components/mdatetimehelper.h


SOURCES += \
    gui/models/qrangemodel.cpp \
    gui/core/mdeclarativeimplicitsizeitem.cpp \
    gui/core/mdeclarativescreen.cpp \
    gui/core/mdeclarativestatusbar.cpp \
    gui/core/mscrolldecoratorsizer.cpp \
    gui/components/mdatetimehelper.cpp \

greaterThan(QT_MAJOR_VERSION, 4) {
# Tweaks sources and headers for Qt5

HEADERS += \
    gui/core/compat/mdeclarativescreen.h \
    gui/core/compat/mdeclarativestatusbar.h
}

!greaterThan(QT_MAJOR_VERSION, 4) {
HEADERS += \
    gui/core/mdeclarativescreen.h \
    gui/core/mdeclarativestatusbar.h \
    gui/core/mdeclarativeview.h \
    gui/core/msnapshot.h \
    gui/components/mdeclarativemaskeditem.h

SOURCES += \
    gui/core/msnapshot.cpp \
    gui/core/mdeclarativeview.cpp \
    gui/components/mdeclarativemaskeditem.cpp
}

