/****************************************************************************
** Meta object code from reading C++ file 'mwindowstate.h'
**
** Created: Mon Aug 27 22:53:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mwindowstate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mwindowstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MWindowState[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       5,   49, // properties
       1,   69, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      30,   13,   13,   13, 0x05,
      48,   13,   13,   13, 0x05,
      65,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   13,   13,   13, 0x08,

 // methods: signature, parameters, type, tag, flags
     131,  116,   13,   13, 0x02,
     162,  116,   13,   13, 0x02,

 // properties: name, type, flags
     199,  194, 0x01495801,
     207,  194, 0x01495801,
     214,  194, 0x01495903,
     233,  224, 0x00495809,
     250,  242, 0x0a495801,

 // properties: notify_signal_id
       2,
       0,
       3,
       1,
       1,

 // enums: name, flags, count, data
     224, 0x0,    2,   73,

 // enum data: key, value
     265, uint(MWindowState::Fullsize),
     274, uint(MWindowState::Thumbnail),

       0        // eod
};

static const char qt_meta_stringdata_MWindowState[] = {
    "MWindowState\0\0activeChanged()\0"
    "viewModeChanged()\0visibleChanged()\0"
    "animatingChanged()\0_q_doVisibleChangedNotVisible()\0"
    "newOrientation\0startSipOrientationChange(int)\0"
    "finishSipOrientationChange(int)\0bool\0"
    "visible\0active\0animating\0ViewMode\0"
    "viewMode\0QString\0viewModeString\0"
    "Fullsize\0Thumbnail\0"
};

void MWindowState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MWindowState *_t = static_cast<MWindowState *>(_o);
        switch (_id) {
        case 0: _t->activeChanged(); break;
        case 1: _t->viewModeChanged(); break;
        case 2: _t->visibleChanged(); break;
        case 3: _t->animatingChanged(); break;
        case 4: _t->_q_doVisibleChangedNotVisible(); break;
        case 5: _t->startSipOrientationChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->finishSipOrientationChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MWindowState::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MWindowState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MWindowState,
      qt_meta_data_MWindowState, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MWindowState::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MWindowState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MWindowState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MWindowState))
        return static_cast<void*>(const_cast< MWindowState*>(this));
    return QObject::qt_metacast(_clname);
}

int MWindowState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = visible(); break;
        case 1: *reinterpret_cast< bool*>(_v) = active(); break;
        case 2: *reinterpret_cast< bool*>(_v) = animating(); break;
        case 3: *reinterpret_cast< ViewMode*>(_v) = viewMode(); break;
        case 4: *reinterpret_cast< QString*>(_v) = viewModeString(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: setAnimating(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MWindowState::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MWindowState::viewModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MWindowState::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MWindowState::animatingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
