include (../../../tests.pri)

TARGET = tst_quickcomponentsprogressbar
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsprogressbar.cpp
OTHER_FILES += tst_quickcomponentsprogressbar.qml

include (../../auto.pri)
