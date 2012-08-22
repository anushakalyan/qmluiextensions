/****************************************************************************
** Meta object code from reading C++ file 'apicheck_ratingindicator.h'
**
** Created: Wed Aug 22 20:05:04 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ratingindicator/apicheck_ratingindicator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_ratingindicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckRatingIndicator_t {
    QByteArrayData data[6];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckRatingIndicator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckRatingIndicator_t qt_meta_stringdata_ApiCheckRatingIndicator = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 12),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 12),
QT_MOC_LITERAL(4, 51, 11),
QT_MOC_LITERAL(5, 63, 5)
    },
    "ApiCheckRatingIndicator\0initTestCase\0"
    "\0maximumValue\0ratingValue\0count\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckRatingIndicator[] = {

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

void ApiCheckRatingIndicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckRatingIndicator *_t = static_cast<ApiCheckRatingIndicator *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->maximumValue(); break;
        case 2: _t->ratingValue(); break;
        case 3: _t->count(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckRatingIndicator::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckRatingIndicator.data,
      qt_meta_data_ApiCheckRatingIndicator,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckRatingIndicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckRatingIndicator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckRatingIndicator.stringdata))
        return static_cast<void*>(const_cast< ApiCheckRatingIndicator*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckRatingIndicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
