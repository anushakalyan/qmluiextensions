TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4) {
    include(../../../src/compat/compat.pri)
    QT += widgets qml quick
    # Don't overwrite any existing extrasgallery example on device
    TARGET = qtquickcomponentextragallery
    desktop.files = qtquickcomponentextragallery.desktop
} else {
    include(../util/util.pri)
    QT += declarative
    TARGET = qmlcomponentextragallery
    desktop.files = qmlcomponentextragallery.desktop
}

CONFIG -= app_bundle

# Input
SOURCES += main.cpp

OTHER_FILES += \
    qml/*.qml

desktop.path = $$INSTALL_PREFIX/share/applications
target.path = $$INSTALL_PREFIX/bin

greaterThan(QT_MAJOR_VERSION, 4) {
    copied_qrc_file = $$OUT_PWD/qml2/qmlfiles.qrc

    # Prevent qmake from complaining about missing qrc file
    system($$QMAKE_MKDIR $$OUT_PWD/qml2 && touch $$copied_qrc_file )

    copy_qml_files.commands = $$QMAKE_COPY_DIR $$PWD/qml/* $$OUT_PWD/qml2

    rewrite_qml_files.commands = $$bumpQmlVersion($$OUT_PWD/qml2, 2.0)
    rewrite_qml_files.depends = copy_qml_files

    QMAKE_EXTRA_TARGETS += copy_qml_files rewrite_qml_files
    rcc.depends += copy_qml_files rewrite_qml_files

    RESOURCES = $$copied_qrc_file
} else {
    RESOURCES = qml/qmlfiles.qrc
}

INSTALLS += target desktop
