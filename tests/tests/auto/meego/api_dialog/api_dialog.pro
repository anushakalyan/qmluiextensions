include (../../../tests.pri)

TARGET = tst_quickcomponentsdialog
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsdialog.cpp
OTHER_FILES += tst_quickcomponentsdialog.qml

include (../../auto.pri)
