include (../../../tests.pri)

TARGET = tst_quickcomponentswindow
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentswindow.cpp
OTHER_FILES += tst_quickcomponentswindow.qml

include (../../auto.pri)
