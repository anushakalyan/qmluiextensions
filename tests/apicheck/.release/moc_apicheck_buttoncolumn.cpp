/****************************************************************************
** Meta object code from reading C++ file 'apicheck_buttoncolumn.h'
**
** Created: Wed Aug 22 20:04:52 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../buttoncolumn/apicheck_buttoncolumn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_buttoncolumn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckButtonColumn_t {
    QByteArrayData data[5];
    char stringdata[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckButtonColumn_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckButtonColumn_t qt_meta_stringdata_ApiCheckButtonColumn = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 12),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 9),
QT_MOC_LITERAL(4, 45, 13)
    },
    "ApiCheckButtonColumn\0initTestCase\0\0"
    "exclusive\0checkedButton\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckButtonColumn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08,
       3,    0,   30,    2, 0x08,
       4,    0,   31,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckButtonColumn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckButtonColumn *_t = static_cast<ApiCheckButtonColumn *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->exclusive(); break;
        case 2: _t->checkedButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckButtonColumn::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckButtonColumn.data,
      qt_meta_data_ApiCheckButtonColumn,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckButtonColumn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckButtonColumn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckButtonColumn.stringdata))
        return static_cast<void*>(const_cast< ApiCheckButtonColumn*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckButtonColumn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
