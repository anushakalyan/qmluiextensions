/****************************************************************************
** Meta object code from reading C++ file 'apicheck_searchbox.h'
**
** Created: Wed Aug 22 20:05:07 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../searchbox/apicheck_searchbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_searchbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckSearchBox_t {
    QByteArrayData data[9];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckSearchBox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckSearchBox_t qt_meta_stringdata_ApiCheckSearchBox = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 12),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 10),
QT_MOC_LITERAL(4, 43, 15),
QT_MOC_LITERAL(5, 59, 10),
QT_MOC_LITERAL(6, 70, 13),
QT_MOC_LITERAL(7, 84, 12),
QT_MOC_LITERAL(8, 97, 11)
    },
    "ApiCheckSearchBox\0initTestCase\0\0"
    "backButton\0placeHolderText\0searchText\0"
    "maximumLength\0clearClicked\0backClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckSearchBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08,
       3,    0,   50,    2, 0x08,
       4,    0,   51,    2, 0x08,
       5,    0,   52,    2, 0x08,
       6,    0,   53,    2, 0x08,
       7,    0,   54,    2, 0x08,
       8,    0,   55,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckSearchBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckSearchBox *_t = static_cast<ApiCheckSearchBox *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->backButton(); break;
        case 2: _t->placeHolderText(); break;
        case 3: _t->searchText(); break;
        case 4: _t->maximumLength(); break;
        case 5: _t->clearClicked(); break;
        case 6: _t->backClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckSearchBox::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckSearchBox.data,
      qt_meta_data_ApiCheckSearchBox,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckSearchBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckSearchBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckSearchBox.stringdata))
        return static_cast<void*>(const_cast< ApiCheckSearchBox*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckSearchBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
