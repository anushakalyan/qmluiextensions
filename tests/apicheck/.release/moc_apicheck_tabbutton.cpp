/****************************************************************************
** Meta object code from reading C++ file 'apicheck_tabbutton.h'
**
** Created: Wed Aug 22 20:05:11 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabbutton/apicheck_tabbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_tabbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckTabButton_t {
    QByteArrayData data[4];
    char stringdata[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckTabButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckTabButton_t qt_meta_stringdata_ApiCheckTabButton = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 12),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 3)
    },
    "ApiCheckTabButton\0initTestCase\0\0tab\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckTabButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08,
       3,    0,   25,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckTabButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckTabButton *_t = static_cast<ApiCheckTabButton *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->tab(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckTabButton::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckTabButton.data,
      qt_meta_data_ApiCheckTabButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckTabButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckTabButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckTabButton.stringdata))
        return static_cast<void*>(const_cast< ApiCheckTabButton*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckTabButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
