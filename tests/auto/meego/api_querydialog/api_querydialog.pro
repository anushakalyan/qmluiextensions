include (../../../tests.pri)

TARGET = tst_quickcomponentsquerydialog
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick
} else {
   QT += declarative
}

SOURCES += tst_quickcomponentsquerydialog.cpp
OTHER_FILES += tst_quickcomponentsquerydialog.qml

include (../../auto.pri)
