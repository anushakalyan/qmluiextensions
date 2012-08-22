include (../../../tests.pri)

TARGET = tst_quickcomponentsapplicationwindow
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsapplicationwindow.cpp
OTHER_FILES += tst_quickcomponentsapplicationwindow.qml

include (../../auto.pri)
