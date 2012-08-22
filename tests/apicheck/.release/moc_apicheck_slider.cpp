/****************************************************************************
** Meta object code from reading C++ file 'apicheck_slider.h'
**
** Created: Wed Aug 22 20:05:10 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../slider/apicheck_slider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_slider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckSlider_t {
    QByteArrayData data[12];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckSlider_t qt_meta_stringdata_ApiCheckSlider = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 8),
QT_MOC_LITERAL(4, 38, 12),
QT_MOC_LITERAL(5, 51, 12),
QT_MOC_LITERAL(6, 64, 5),
QT_MOC_LITERAL(7, 70, 11),
QT_MOC_LITERAL(8, 82, 7),
QT_MOC_LITERAL(9, 90, 21),
QT_MOC_LITERAL(10, 112, 18),
QT_MOC_LITERAL(11, 131, 8)
    },
    "ApiCheckSlider\0initTestCase\0\0stepSize\0"
    "minimumValue\0maximumValue\0value\0"
    "orientation\0pressed\0valueIndicatorVisible\0"
    "valueIndicatorText\0inverted\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckSlider[] = {

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

void ApiCheckSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckSlider *_t = static_cast<ApiCheckSlider *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->stepSize(); break;
        case 2: _t->minimumValue(); break;
        case 3: _t->maximumValue(); break;
        case 4: _t->value(); break;
        case 5: _t->orientation(); break;
        case 6: _t->pressed(); break;
        case 7: _t->valueIndicatorVisible(); break;
        case 8: _t->valueIndicatorText(); break;
        case 9: _t->inverted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckSlider::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckSlider.data,
      qt_meta_data_ApiCheckSlider,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckSlider.stringdata))
        return static_cast<void*>(const_cast< ApiCheckSlider*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
