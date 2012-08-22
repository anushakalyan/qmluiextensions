/****************************************************************************
** Meta object code from reading C++ file 'apicheck_checkbox.h'
**
** Created: Wed Aug 22 20:04:54 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../checkbox/apicheck_checkbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_checkbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckCheckBox_t {
    QByteArrayData data[6];
    char stringdata[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckCheckBox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckCheckBox_t qt_meta_stringdata_ApiCheckCheckBox = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 12),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 7),
QT_MOC_LITERAL(4, 39, 7),
QT_MOC_LITERAL(5, 47, 7)
    },
    "ApiCheckCheckBox\0initTestCase\0\0checked\0"
    "pressed\0clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckCheckBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    0,   35,    2, 0x08,
       4,    0,   36,    2, 0x08,
       5,    0,   37,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckCheckBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckCheckBox *_t = static_cast<ApiCheckCheckBox *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->checked(); break;
        case 2: _t->pressed(); break;
        case 3: _t->clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckCheckBox::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckCheckBox.data,
      qt_meta_data_ApiCheckCheckBox,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckCheckBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckCheckBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckCheckBox.stringdata))
        return static_cast<void*>(const_cast< ApiCheckCheckBox*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckCheckBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
