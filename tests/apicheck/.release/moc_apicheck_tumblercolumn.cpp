/****************************************************************************
** Meta object code from reading C++ file 'apicheck_tumblercolumn.h'
**
** Created: Wed Aug 22 20:05:18 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tumbler/apicheck_tumblercolumn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_tumblercolumn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckTumblerColumn_t {
    QByteArrayData data[7];
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckTumblerColumn_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckTumblerColumn_t qt_meta_stringdata_ApiCheckTumblerColumn = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 12),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 5),
QT_MOC_LITERAL(4, 42, 5),
QT_MOC_LITERAL(5, 48, 13),
QT_MOC_LITERAL(6, 62, 7)
    },
    "ApiCheckTumblerColumn\0initTestCase\0\0"
    "label\0items\0selectedIndex\0enabled\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckTumblerColumn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08,
       3,    0,   40,    2, 0x08,
       4,    0,   41,    2, 0x08,
       5,    0,   42,    2, 0x08,
       6,    0,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckTumblerColumn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckTumblerColumn *_t = static_cast<ApiCheckTumblerColumn *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->label(); break;
        case 2: _t->items(); break;
        case 3: _t->selectedIndex(); break;
        case 4: _t->enabled(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckTumblerColumn::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckTumblerColumn.data,
      qt_meta_data_ApiCheckTumblerColumn,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckTumblerColumn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckTumblerColumn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckTumblerColumn.stringdata))
        return static_cast<void*>(const_cast< ApiCheckTumblerColumn*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckTumblerColumn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
