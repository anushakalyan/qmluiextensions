include (../../../tests.pri)

TARGET = tst_quickcomponentstextfield
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentstextfield.cpp
OTHER_FILES += tst_quickcomponentstextfield.qml

include (../../auto.pri)
