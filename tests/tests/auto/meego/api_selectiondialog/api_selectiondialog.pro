include (../../../tests.pri)

TARGET = tst_quickcomponentsselectiondialog
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsselectiondialog.cpp
OTHER_FILES += tst_quickcomponentsselectiondialog.qml

include (../../auto.pri)
