include (../../../tests.pri)

TARGET = tst_quickcomponentspagestack
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentspagestack.cpp
OTHER_FILES += tst_quickcomponentspagestack.qml

include (../../auto.pri)
