include (../../../tests.pri)

TARGET = tst_quickcomponentstabgroup
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentstabgroup.cpp
OTHER_FILES += tst_quickcomponentstabgroup.qml

include (../../auto.pri)
