TEMPLATE = app
QT += network
greaterThan(QT_MAJOR_VERSION, 4) {
   include(../../../src/compat/compat.pri)
   QT += qml quick
   # Don't overwrite any existing flickr example on device.
   # We dont need this When the whole migration to q5
   # is done
   TARGET = qtquickflickr
   desktop.files = qtquickflickrapplication.desktop
} else {
   QT += declarative
   TARGET = flickr
   desktop.files = flickrapplication.desktop
}

SOURCES += main.cpp

OTHER_FILES += \
    qml/*.qml \
    qml/*.js \
    qml/images/* \
    *.svg

desktop.path = $$INSTALL_PREFIX/share/applications
target.path = $$INSTALL_PREFIX/bin

CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4) {
    copied_qrc_file = $$OUT_PWD/qml2/flickr.qrc

    # Prevent qmake from complaining about missing qrc file
    system($$QMAKE_MKDIR $$OUT_PWD/qml2 && touch $$copied_qrc_file )

    copy_qml_files.commands = $$QMAKE_COPY_DIR $$PWD/qml/* $$OUT_PWD/qml2

    rewrite_qml_files.commands = $$bumpQmlVersion($$OUT_PWD/qml2, 2.0)
    rewrite_qml_files.depends = copy_qml_files

    QMAKE_EXTRA_TARGETS += copy_qml_files rewrite_qml_files
    rcc.depends += copy_qml_files rewrite_qml_files

    RESOURCES = $$copied_qrc_file
} else {
    RESOURCES = qml/flickr.qrc
}

INSTALLS += target desktop
