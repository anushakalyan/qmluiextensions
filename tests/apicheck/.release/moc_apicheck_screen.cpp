/****************************************************************************
** Meta object code from reading C++ file 'apicheck_screen.h'
**
** Created: Wed Aug 22 20:05:05 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screen/apicheck_screen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_screen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckScreen_t {
    QByteArrayData data[17];
    char stringdata[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckScreen_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckScreen_t qt_meta_stringdata_ApiCheckScreen = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 5),
QT_MOC_LITERAL(4, 35, 6),
QT_MOC_LITERAL(5, 42, 12),
QT_MOC_LITERAL(6, 55, 13),
QT_MOC_LITERAL(7, 69, 8),
QT_MOC_LITERAL(8, 78, 18),
QT_MOC_LITERAL(9, 97, 19),
QT_MOC_LITERAL(10, 117, 3),
QT_MOC_LITERAL(11, 121, 15),
QT_MOC_LITERAL(12, 137, 7),
QT_MOC_LITERAL(13, 145, 12),
QT_MOC_LITERAL(14, 158, 13),
QT_MOC_LITERAL(15, 172, 25),
QT_MOC_LITERAL(16, 198, 26)
    },
    "ApiCheckScreen\0initTestCase\0\0width\0"
    "height\0displayWidth\0displayHeight\0"
    "rotation\0currentOrientation\0"
    "allowedOrientations\0dpi\0displayCategory\0"
    "density\0widthChanged\0heightChanged\0"
    "currentOrientationChanged\0"
    "allowedOrientationsChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08,
       3,    0,   90,    2, 0x08,
       4,    0,   91,    2, 0x08,
       5,    0,   92,    2, 0x08,
       6,    0,   93,    2, 0x08,
       7,    0,   94,    2, 0x08,
       8,    0,   95,    2, 0x08,
       9,    0,   96,    2, 0x08,
      10,    0,   97,    2, 0x08,
      11,    0,   98,    2, 0x08,
      12,    0,   99,    2, 0x08,
      13,    0,  100,    2, 0x08,
      14,    0,  101,    2, 0x08,
      15,    0,  102,    2, 0x08,
      16,    0,  103,    2, 0x08,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApiCheckScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckScreen *_t = static_cast<ApiCheckScreen *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->width(); break;
        case 2: _t->height(); break;
        case 3: _t->displayWidth(); break;
        case 4: _t->displayHeight(); break;
        case 5: _t->rotation(); break;
        case 6: _t->currentOrientation(); break;
        case 7: _t->allowedOrientations(); break;
        case 8: _t->dpi(); break;
        case 9: _t->displayCategory(); break;
        case 10: _t->density(); break;
        case 11: _t->widthChanged(); break;
        case 12: _t->heightChanged(); break;
        case 13: _t->currentOrientationChanged(); break;
        case 14: _t->allowedOrientationsChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckScreen::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckScreen.data,
      qt_meta_data_ApiCheckScreen,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckScreen.stringdata))
        return static_cast<void*>(const_cast< ApiCheckScreen*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE