/****************************************************************************
** Meta object code from reading C++ file 'apicheck_menu.h'
**
** Created: Wed Aug 22 20:04:58 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu/apicheck_menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckMenu_t {
    QByteArrayData data[8];
    char stringdata[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckMenu_t qt_meta_stringdata_ApiCheckMenu = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 7),
QT_MOC_LITERAL(4, 35, 4),
QT_MOC_LITERAL(5, 40, 5),
QT_MOC_LITERAL(6, 46, 12),
QT_MOC_LITERAL(7, 59, 6)
    },
    "ApiCheckMenu\0initTestCase\0\0content\0"
    "open\0close\0visualParent\0status\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    0,   46,    2, 0x08,
       5,    0,   47,    2, 0x08,
       6,    0,   48,    2, 0x08,
       7,    0,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckMenu *_t = static_cast<ApiCheckMenu *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->content(); break;
        case 2: _t->open(); break;
        case 3: _t->close(); break;
        case 4: _t->visualParent(); break;
        case 5: _t->status(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckMenu::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckMenu.data,
      qt_meta_data_ApiCheckMenu,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckMenu.stringdata))
        return static_cast<void*>(const_cast< ApiCheckMenu*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
