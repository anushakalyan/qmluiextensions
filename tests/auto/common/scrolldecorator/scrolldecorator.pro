include (../../../../qt-components.pri)
include (../../../tests.pri)

TARGET = tst_quickcomponentsscrolldecorator
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsscrolldecorator.cpp
OTHER_FILES += tst_quickcomponentsscrolldecorator.qml

include (../../auto.pri)
