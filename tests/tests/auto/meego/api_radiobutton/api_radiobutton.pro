include (../../../tests.pri)

TARGET = tst_quickcomponentsradiobutton
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsradiobutton.cpp
OTHER_FILES += tst_quickcomponentsradiobutton.qml

include (../../auto.pri)
