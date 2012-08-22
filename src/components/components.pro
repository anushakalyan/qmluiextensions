include (../../qt-components.pri)
symbian3 { TARGETPATH = Qt/labs/components.1.1 }
else { TARGETPATH = Qt/labs/components }
TEMPLATE = lib
TARGET = $$qtLibraryTarget(qtcomponentsplugin)
INCLUDEPATH += $$PWD $$PWD/models

win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
CONFIG += qt plugin
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += qml quick
    OTHER_FILES += qmlcomponentsplugin.json
} else {
    QT += declarative
}

DEFINES += QT_BUILD_COMPONENTS_LIB

QML_FILES += \
    qmldir \
    Checkable.qml \
    CheckableGroup.qml \
    CheckableGroup.js

symbian {
    TARGET.EPOCALLOWDLLDATA = 1
    TARGET.CAPABILITY = ALL -TCB
    TARGET.UID3 = 0x2003DF67
    MMP_RULES += SMPSAFE
    VERSION = 10.1.2

    vendor_info = \
            " " \
            "; Localised Vendor name" \
            "%{\"Nokia\"}" \
            " " \
            "; Unique Vendor name" \
            ":\"Nokia\"" \
            " "

    package.pkg_prerules += vendor_info
    DEPLOYMENT += package

    defBlock = \
        "$${LITERAL_HASH}ifdef WINSCW" \
        "DEFFILE  bwins/components.def" \
        "$${LITERAL_HASH}elif defined EABI" \
        "DEFFILE  eabi/components.def" \
        "$${LITERAL_HASH}endif"
    MMP_RULES += defBlock
}

HEADERS += qglobalenums.h

SOURCES += plugin.cpp

include(kernel/kernel.pri)

include(models/models.pri)

include(../../qml.pri)
