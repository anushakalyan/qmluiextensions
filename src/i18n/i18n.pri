HEADERS += \
    i18n/mdeclarativeimattributeextension.h \
    i18n/mdeclarativeimobserver.h \
    i18n/mdeclarativeinputcontext.h \
    i18n/mdeclarativerichtexthandler.h \
    i18n/mlocalewrapper.h \
    i18n/mtexttranslator.h

SOURCES += \
    i18n/mdeclarativeimattributeextension.cpp \
    i18n/mdeclarativeimobserver.cpp \
    i18n/mdeclarativerichtexthandler.cpp \
    i18n/mtexttranslator.cpp

greaterThan(QT_MAJOR_VERSION, 4) {
# Tweaks sources and headers for Qt5
HEADERS += \
    i18n/compat/mdeclarativeinputcontext.h

SOURCES += \
    i18n/compat/mdeclarativeinputcontext.cpp
}

!greaterThan(QT_MAJOR_VERSION, 4) {
HEADERS += \
    i18n/mdeclarativeinputcontext.h

SOURCES += \
    i18n/mdeclarativeinputcontext.cpp
}
