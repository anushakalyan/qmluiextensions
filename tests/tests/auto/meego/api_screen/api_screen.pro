include (../../../tests.pri)

TARGET = tst_quickcomponentsscreen
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsscreen.cpp
OTHER_FILES += tst_quickcomponentsscreen.qml

include (../../auto.pri)
