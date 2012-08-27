/****************************************************************************
** Meta object code from reading C++ file 'mdeclarativeimplicitsizeitem.h'
**
** Created: Mon Aug 27 22:52:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdeclarativeimplicitsizeitem.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdeclarativeimplicitsizeitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDeclarativeImplicitSizeItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       4,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x05,
      53,   29,   29,   29, 0x05,
      77,   29,   29,   29, 0x05,

 // properties: name, type, flags
     110,  104, ((uint)QMetaType::QReal << 24) | 0x00495003,
     124,  104, ((uint)QMetaType::QReal << 24) | 0x00495003,
     144,  139, 0x01495003,
     154,  139, 0x01495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       2,

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeImplicitSizeItem[] = {
    "MDeclarativeImplicitSizeItem\0\0"
    "implicitWidthChanged()\0implicitHeightChanged()\0"
    "platformFocusableChanged()\0qreal\0"
    "implicitWidth\0implicitHeight\0bool\0"
    "focusable\0platformFocusable\0"
};

void MDeclarativeImplicitSizeItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDeclarativeImplicitSizeItem *_t = static_cast<MDeclarativeImplicitSizeItem *>(_o);
        switch (_id) {
        case 0: _t->implicitWidthChanged(); break;
        case 1: _t->implicitHeightChanged(); break;
        case 2: _t->platformFocusableChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MDeclarativeImplicitSizeItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDeclarativeImplicitSizeItem::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MDeclarativeImplicitSizeItem,
      qt_meta_data_MDeclarativeImplicitSizeItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeImplicitSizeItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeImplicitSizeItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeImplicitSizeItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeImplicitSizeItem))
        return static_cast<void*>(const_cast< MDeclarativeImplicitSizeItem*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MDeclarativeImplicitSizeItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = implicitWidth(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = implicitHeight(); break;
        case 2: *reinterpret_cast< bool*>(_v) = platformFocusable(); break;
        case 3: *reinterpret_cast< bool*>(_v) = platformFocusable(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setImplicitWidthNotify(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setImplicitHeightNotify(*reinterpret_cast< qreal*>(_v)); break;
        case 2: setPlatformFocusable(*reinterpret_cast< bool*>(_v)); break;
        case 3: setPlatformFocusable(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MDeclarativeImplicitSizeItem::implicitWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MDeclarativeImplicitSizeItem::implicitHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MDeclarativeImplicitSizeItem::platformFocusableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
