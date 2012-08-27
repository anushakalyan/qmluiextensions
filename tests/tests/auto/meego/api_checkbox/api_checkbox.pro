include (../../../tests.pri)

TARGET = tst_quickcomponentscheckbox
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentscheckbox.cpp
OTHER_FILES += tst_quickcomponentscheckbox.qml

include (../../auto.pri)
