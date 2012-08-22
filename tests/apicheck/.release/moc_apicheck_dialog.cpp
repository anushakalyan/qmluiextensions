/****************************************************************************
** Meta object code from reading C++ file 'apicheck_dialog.h'
**
** Created: Wed Aug 22 20:04:56 2012
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog/apicheck_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apicheck_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApiCheckDialog_t {
    QByteArrayData data[15];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ApiCheckDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ApiCheckDialog_t qt_meta_stringdata_ApiCheckDialog = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 5),
QT_MOC_LITERAL(4, 35, 7),
QT_MOC_LITERAL(5, 43, 7),
QT_MOC_LITERAL(6, 51, 4),
QT_MOC_LITERAL(7, 56, 6),
QT_MOC_LITERAL(8, 63, 6),
QT_MOC_LITERAL(9, 70, 5),
QT_MOC_LITERAL(10, 76, 12),
QT_MOC_LITERAL(11, 89, 6),
QT_MOC_LITERAL(12, 96, 8),
QT_MOC_LITERAL(13, 105, 8),
QT_MOC_LITERAL(14, 114, 14)
    },
    "ApiCheckDialog\0initTestCase\0\0title\0"
    "content\0buttons\0open\0accept\0reject\0"
    "close\0visualParent\0status\0accepted\0"
    "rejected\0clickedOutside\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiCheckDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08,
       3,    0,   80,    2, 0x08,
       4,    0,   81,    2, 0x08,
       5,    0,   82,    2, 0x08,
       6,    0,   83,    2, 0x08,
       7,    0,   84,    2, 0x08,
       8,    0,   85,    2, 0x08,
       9,    0,   86,    2, 0x08,
      10,    0,   87,    2, 0x08,
      11,    0,   88,    2, 0x08,
      12,    0,   89,    2, 0x08,
      13,    0,   90,    2, 0x08,
      14,    0,   91,    2, 0x08,

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

       0        // eod
};

void ApiCheckDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApiCheckDialog *_t = static_cast<ApiCheckDialog *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->title(); break;
        case 2: _t->content(); break;
        case 3: _t->buttons(); break;
        case 4: _t->open(); break;
        case 5: _t->accept(); break;
        case 6: _t->reject(); break;
        case 7: _t->close(); break;
        case 8: _t->visualParent(); break;
        case 9: _t->status(); break;
        case 10: _t->accepted(); break;
        case 11: _t->rejected(); break;
        case 12: _t->clickedOutside(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ApiCheckDialog::staticMetaObject = {
    { &ApiCheckBase::staticMetaObject, qt_meta_stringdata_ApiCheckDialog.data,
      qt_meta_data_ApiCheckDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *ApiCheckDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiCheckDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApiCheckDialog.stringdata))
        return static_cast<void*>(const_cast< ApiCheckDialog*>(this));
    return ApiCheckBase::qt_metacast(_clname);
}

int ApiCheckDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApiCheckBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
