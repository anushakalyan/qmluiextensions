include (../../../tests.pri)

TARGET = tst_quickcomponentsbusyindicator
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsbusyindicator.cpp
OTHER_FILES += tst_quickcomponentsbusyindicator.qml

include (../../auto.pri)