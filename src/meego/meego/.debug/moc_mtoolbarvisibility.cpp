/****************************************************************************
** Meta object code from reading C++ file 'mtoolbarvisibility.h'
**
** Created: Mon Aug 27 22:52:42 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mtoolbarvisibility.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mtoolbarvisibility.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MToolBarVisibility[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
      19, 0x0,    3,   18,

 // enum data: key, value
      30, uint(MToolBarVisibility::Visible),
      38, uint(MToolBarVisibility::Hidden),
      45, uint(MToolBarVisibility::HiddenImmediately),

       0        // eod
};

static const char qt_meta_stringdata_MToolBarVisibility[] = {
    "MToolBarVisibility\0Visibility\0Visible\0"
    "Hidden\0HiddenImmediately\0"
};

void MToolBarVisibility::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MToolBarVisibility::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MToolBarVisibility::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MToolBarVisibility,
      qt_meta_data_MToolBarVisibility, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MToolBarVisibility::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MToolBarVisibility::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MToolBarVisibility::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MToolBarVisibility))
        return static_cast<void*>(const_cast< MToolBarVisibility*>(this));
    return QObject::qt_metacast(_clname);
}

int MToolBarVisibility::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
