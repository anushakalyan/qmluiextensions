
HEADERS += \
    platform/meego/*.h

SOURCES += \
    platform/meego/*.cpp \

greaterThan(QT_MAJOR_VERSION, 4) {
# Tweaks sources and headers for Qt5
HEADERS -= \
    platform/meego/qmlwindoweventhandler_x11.h
HEADERS += \
    platform/meego/compat/qmlwindoweventhandler_x11.h
}
