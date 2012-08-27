/****************************************************************************
** Meta object code from reading C++ file 'mdeclarativeimobserver.h'
**
** Created: Mon Aug 27 22:52:34 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdeclarativeimobserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdeclarativeimobserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDeclarativeIMObserver[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,
      41,   23,   23,   23, 0x05,

 // properties: name, type, flags
      80,   72, 0x0a495001,
      92,   88, 0x02495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeIMObserver[] = {
    "MDeclarativeIMObserver\0\0preeditChanged()\0"
    "preeditCursorPositionChanged()\0QString\0"
    "preedit\0int\0preeditCursorPosition\0"
};

void MDeclarativeIMObserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDeclarativeIMObserver *_t = static_cast<MDeclarativeIMObserver *>(_o);
        switch (_id) {
        case 0: _t->preeditChanged(); break;
        case 1: _t->preeditCursorPositionChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MDeclarativeIMObserver::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDeclarativeIMObserver::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MDeclarativeIMObserver,
      qt_meta_data_MDeclarativeIMObserver, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeIMObserver::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeIMObserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeIMObserver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeIMObserver))
        return static_cast<void*>(const_cast< MDeclarativeIMObserver*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MDeclarativeIMObserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = preedit(); break;
        case 1: *reinterpret_cast< int*>(_v) = preeditCursorPosition(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
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
void MDeclarativeIMObserver::preeditChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MDeclarativeIMObserver::preeditCursorPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
