include (../../../../qt-components.pri)
include (../../../tests.pri)

TARGET = tst_quickcomponentsswitch
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsswitch.cpp
OTHER_FILES += tst_quickcomponentsswitch.qml

include (../../auto.pri)
