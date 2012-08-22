include (../../../tests.pri)

TARGET = tst_quickcomponentsslider
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsslider.cpp
OTHER_FILES += tst_quickcomponentsslider.qml

include (../../auto.pri)
