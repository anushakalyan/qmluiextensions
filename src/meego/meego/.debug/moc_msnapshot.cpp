/****************************************************************************
** Meta object code from reading C++ file 'msnapshot.h'
**
** Created: Mon Aug 27 22:52:54 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../msnapshot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'msnapshot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSnapshot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      34,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   10,   10,   10, 0x0a,
      65,   10,   10,   10, 0x0a,

 // properties: name, type, flags
      76,   72, 0x02495103,
      90,   72, 0x02495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_MSnapshot[] = {
    "MSnapshot\0\0snapshotWidthChanged()\0"
    "snapshotHeightChanged()\0take()\0free()\0"
    "int\0snapshotWidth\0snapshotHeight\0"
};

void MSnapshot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSnapshot *_t = static_cast<MSnapshot *>(_o);
        switch (_id) {
        case 0: _t->snapshotWidthChanged(); break;
        case 1: _t->snapshotHeightChanged(); break;
        case 2: _t->take(); break;
        case 3: _t->free(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MSnapshot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSnapshot::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MSnapshot,
      qt_meta_data_MSnapshot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSnapshot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSnapshot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSnapshot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSnapshot))
        return static_cast<void*>(const_cast< MSnapshot*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MSnapshot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = snapshotWidth(); break;
        case 1: *reinterpret_cast< int*>(_v) = snapshotHeight(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setSnapshotWidth(*reinterpret_cast< int*>(_v)); break;
        case 1: setSnapshotHeight(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MSnapshot::snapshotWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MSnapshot::snapshotHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
