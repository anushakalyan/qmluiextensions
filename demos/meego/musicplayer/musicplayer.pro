TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   include(../../../src/compat/compat.pri)
   QT += qml quick
   # Don't overwrite any existing musicplayer example on device
   TARGET = qtquickmusicplayer
   desktop.files = qtquickmusicplayerapplication.desktop
} else {
   QT += declarative
   TARGET = musicplayer
   desktop.files = musicplayerapplication.desktop
}
CONFIG += mobility
SOURCES += main.cpp

OTHER_FILES += \
    qml/*.qml \
    qml/Storage.js

desktop.path = $$INSTALL_PREFIX/share/applications
target.path = $$INSTALL_PREFIX/bin

CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4) {
    copied_qrc_file = $$OUT_PWD/qml2/resources.qrc

    # Prevent qmake from complaining about missing qrc file
    system($$QMAKE_MKDIR $$OUT_PWD/qml2 && touch $$copied_qrc_file )

    copy_qml_files.commands = $$QMAKE_COPY_DIR $$PWD/qml/* $$OUT_PWD/qml2

    rewrite_qml_files.commands = $$bumpQmlVersion($$OUT_PWD/qml2, 2.0)
    rewrite_qml_files.depends = copy_qml_files

    QMAKE_EXTRA_TARGETS += copy_qml_files rewrite_qml_files
    rcc.depends += copy_qml_files rewrite_qml_files

    RESOURCES = $$copied_qrc_file
} else {
    RESOURCES = qml/resources.qrc
}

INSTALLS += target desktop
