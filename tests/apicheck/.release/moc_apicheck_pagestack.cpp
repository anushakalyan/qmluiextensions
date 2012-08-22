/****************************************************************************
** Meta object code from reading C++ file 'apicheck_pagestack.h'
**
** Created: Wed Aug 22 20:05:01 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pagestack/apicheck_pagestack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_pagestack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckPageStack_t {
    QByteArrayData data[12];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckPageStack_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckPageStack_t qt_meta_stringdata_ApiCheckPageStack = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 12),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 5),
QT_MOC_LITERAL(4, 38, 11),
QT_MOC_LITERAL(5, 50, 7),
QT_MOC_LITERAL(6, 58, 4),
QT_MOC_LITERAL(7, 63, 4),
QT_MOC_LITERAL(8, 68, 3),
QT_MOC_LITERAL(9, 72, 7),
QT_MOC_LITERAL(10, 80, 5),
QT_MOC_LITERAL(11, 86, 4)
    },
    "ApiCheckPageStack\0initTestCase\0\0depth\0"
    "currentPage\0toolBar\0busy\0push\0pop\0"
    "replace\0clear\0find\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckPageStack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08,
       3,    0,   65,    2, 0x08,
       4,    0,   66,    2, 0x08,
       5,    0,   67,    2, 0x08,
       6,    0,   68,    2, 0x08,
       7,    0,   69,    2, 0x08,
       8,    0,   70,    2, 0x08,
       9,    0,   71,    2, 0x08,
      10,    0,   72,    2, 0x08,
      11,    0,   73,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckPageStack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckPageStack *_t = static_cast<ApiCheckPageStack *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->depth(); break;
        case 2: _t->currentPage(); break;
        case 3: _t->toolBar(); break;
        case 4: _t->busy(); break;
        case 5: _t->push(); break;
        case 6: _t->pop(); break;
        case 7: _t->replace(); break;
        case 8: _t->clear(); break;
        case 9: _t->find(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckPageStack::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckPageStack.data,
      qt_meta_data_ApiCheckPageStack,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckPageStack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckPageStack::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckPageStack.stringdata))
        return static_cast<void*>(const_cast< ApiCheckPageStack*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckPageStack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
