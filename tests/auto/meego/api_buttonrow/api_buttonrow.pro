include (../../../tests.pri)

TARGET = tst_quickcomponentsbuttonrow
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsbuttonrow.cpp
OTHER_FILES += tst_quickcomponentsbuttonrow.qml

include (../../auto.pri)
