/****************************************************************************
** Meta object code from reading C++ file 'mpageorientation.h'
**
** Created: Mon Aug 27 22:52:41 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mpageorientation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mpageorientation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MPageOrientation[] = {

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
      17, 0x0,    4,   18,

 // enum data: key, value
      33, uint(MPageOrientation::Automatic),
      43, uint(MPageOrientation::LockPortrait),
      56, uint(MPageOrientation::LockLandscape),
      70, uint(MPageOrientation::LockPrevious),

       0        // eod
};

static const char qt_meta_stringdata_MPageOrientation[] = {
    "MPageOrientation\0PageOrientation\0"
    "Automatic\0LockPortrait\0LockLandscape\0"
    "LockPrevious\0"
};

void MPageOrientation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MPageOrientation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MPageOrientation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MPageOrientation,
      qt_meta_data_MPageOrientation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MPageOrientation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MPageOrientation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MPageOrientation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MPageOrientation))
        return static_cast<void*>(const_cast< MPageOrientation*>(this));
    return QObject::qt_metacast(_clname);
}

int MPageOrientation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
