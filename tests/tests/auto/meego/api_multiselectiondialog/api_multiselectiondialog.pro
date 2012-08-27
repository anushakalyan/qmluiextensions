include (../../../tests.pri)

TARGET = tst_quickcomponentsmultiselectiondialog
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsmultiselectiondialog.cpp
OTHER_FILES += tst_quickcomponentsmultiselectiondialog.qml

include (../../auto.pri)
