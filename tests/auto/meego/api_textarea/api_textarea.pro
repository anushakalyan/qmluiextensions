include (../../../tests.pri)

TARGET = tst_quickcomponentstextarea
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentstextarea.cpp
OTHER_FILES += tst_quickcomponentstextarea.qml

include (../../auto.pri)
