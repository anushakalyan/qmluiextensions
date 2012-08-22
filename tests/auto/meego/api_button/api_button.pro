include (../../../tests.pri)

TARGET = tst_quickcomponentsbutton
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsbutton.cpp
OTHER_FILES += tst_quickcomponentsbutton.qml

include (../../auto.pri)
