/****************************************************************************
** Meta object code from reading C++ file 'mdeclarativemousefilter.h'
**
** Created: Mon Aug 27 22:52:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdeclarativemousefilter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdeclarativemousefilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDeclarativeMouseEvent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      27,   23, 0x02095001,
      29,   23, 0x02095001,
      36,   31, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeMouseEvent[] = {
    "MDeclarativeMouseEvent\0int\0x\0y\0bool\0"
    "filtered\0"
};

void MDeclarativeMouseEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MDeclarativeMouseEvent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDeclarativeMouseEvent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MDeclarativeMouseEvent,
      qt_meta_data_MDeclarativeMouseEvent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeMouseEvent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeMouseEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeMouseEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeMouseEvent))
        return static_cast<void*>(const_cast< MDeclarativeMouseEvent*>(this));
    return QObject::qt_metacast(_clname);
}

int MDeclarativeMouseEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = x(); break;
        case 1: *reinterpret_cast< int*>(_v) = y(); break;
        case 2: *reinterpret_cast< bool*>(_v) = isFiltered(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: setFiltered(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
static const uint qt_meta_data_MDeclarativeMouseFilter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   25,   24,   24, 0x05,
      77,   25,   24,   24, 0x05,
     110,   24,   24,   24, 0x05,
     129,   25,   24,   24, 0x05,
     167,   25,   24,   24, 0x05,
     201,   24,   24,   24, 0x05,
     212,   24,   24,   24, 0x05,
     229,   25,   24,   24, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeMouseFilter[] = {
    "MDeclarativeMouseFilter\0\0mouse\0"
    "mousePositionChanged(MDeclarativeMouseEvent*)\0"
    "pressed(MDeclarativeMouseEvent*)\0"
    "delayedPressSent()\0"
    "pressAndHold(MDeclarativeMouseEvent*)\0"
    "released(MDeclarativeMouseEvent*)\0"
    "finished()\0horizontalDrag()\0"
    "doubleClicked(MDeclarativeMouseEvent*)\0"
};

void MDeclarativeMouseFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDeclarativeMouseFilter *_t = static_cast<MDeclarativeMouseFilter *>(_o);
        switch (_id) {
        case 0: _t->mousePositionChanged((*reinterpret_cast< MDeclarativeMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->pressed((*reinterpret_cast< MDeclarativeMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->delayedPressSent(); break;
        case 3: _t->pressAndHold((*reinterpret_cast< MDeclarativeMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->released((*reinterpret_cast< MDeclarativeMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->finished(); break;
        case 6: _t->horizontalDrag(); break;
        case 7: _t->doubleClicked((*reinterpret_cast< MDeclarativeMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MDeclarativeMouseFilter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDeclarativeMouseFilter::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MDeclarativeMouseFilter,
      qt_meta_data_MDeclarativeMouseFilter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeMouseFilter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeMouseFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeMouseFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeMouseFilter))
        return static_cast<void*>(const_cast< MDeclarativeMouseFilter*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MDeclarativeMouseFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MDeclarativeMouseFilter::mousePositionChanged(MDeclarativeMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MDeclarativeMouseFilter::pressed(MDeclarativeMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MDeclarativeMouseFilter::delayedPressSent()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MDeclarativeMouseFilter::pressAndHold(MDeclarativeMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MDeclarativeMouseFilter::released(MDeclarativeMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MDeclarativeMouseFilter::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MDeclarativeMouseFilter::horizontalDrag()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MDeclarativeMouseFilter::doubleClicked(MDeclarativeMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
