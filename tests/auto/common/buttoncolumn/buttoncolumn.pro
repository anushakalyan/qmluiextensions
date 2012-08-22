include (../../../../qt-components.pri)
include (../../../tests.pri)

TARGET = tst_quickcomponentsbuttoncolumn
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsbuttoncolumn.cpp
OTHER_FILES += tst_quickcomponentsbuttoncolumn.qml

include (../../auto.pri)
