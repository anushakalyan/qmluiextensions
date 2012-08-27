include (../../../tests.pri)

TARGET = tst_quickcomponentstoolbar
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentstoolbar.cpp
OTHER_FILES += tst_quickcomponentstoolbar.qml 

include (../../auto.pri)
