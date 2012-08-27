/****************************************************************************
** Meta object code from reading C++ file 'mdeclarativeimattributeextension.h'
**
** Created: Mon Aug 27 22:52:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdeclarativeimattributeextension.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdeclarativeimattributeextension.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDeclarativeIMAttributeExtension[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   33,   33,   33, 0x05,
      64,   33,   33,   33, 0x05,
      90,   33,   33,   33, 0x05,
     114,   33,   33,   33, 0x05,

 // methods: signature, parameters, type, tag, flags
     145,  137,   33,   33, 0x02,

 // properties: name, type, flags
     190,  185, 0x01495103,
     211,  185, 0x01495103,
     236,  228, 0x0a495103,
     251,  228, 0x0a495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeIMAttributeExtension[] = {
    "MDeclarativeIMAttributeExtension\0\0"
    "actionKeyHighlightedChanged()\0"
    "actionKeyEnabledChanged()\0"
    "actionKeyLabelChanged()\0actionKeyIconChanged()\0"
    "element\0registerInputElement(QDeclarativeItem*)\0"
    "bool\0actionKeyHighlighted\0actionKeyEnabled\0"
    "QString\0actionKeyLabel\0actionKeyIcon\0"
};

void MDeclarativeIMAttributeExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDeclarativeIMAttributeExtension *_t = static_cast<MDeclarativeIMAttributeExtension *>(_o);
        switch (_id) {
        case 0: _t->actionKeyHighlightedChanged(); break;
        case 1: _t->actionKeyEnabledChanged(); break;
        case 2: _t->actionKeyLabelChanged(); break;
        case 3: _t->actionKeyIconChanged(); break;
        case 4: _t->registerInputElement((*reinterpret_cast< QDeclarativeItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MDeclarativeIMAttributeExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDeclarativeIMAttributeExtension::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MDeclarativeIMAttributeExtension,
      qt_meta_data_MDeclarativeIMAttributeExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeIMAttributeExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeIMAttributeExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeIMAttributeExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeIMAttributeExtension))
        return static_cast<void*>(const_cast< MDeclarativeIMAttributeExtension*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MDeclarativeIMAttributeExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isActionKeyHighlighted(); break;
        case 1: *reinterpret_cast< bool*>(_v) = isActionKeyEnabled(); break;
        case 2: *reinterpret_cast< QString*>(_v) = actionKeyLabel(); break;
        case 3: *reinterpret_cast< QString*>(_v) = actionKeyIcon(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setActionKeyHighlighted(*reinterpret_cast< bool*>(_v)); break;
        case 1: setActionKeyEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 2: setActionKeyLabel(*reinterpret_cast< QString*>(_v)); break;
        case 3: setActionKeyIcon(*reinterpret_cast< QString*>(_v)); break;
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
void MDeclarativeIMAttributeExtension::actionKeyHighlightedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MDeclarativeIMAttributeExtension::actionKeyEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MDeclarativeIMAttributeExtension::actionKeyLabelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MDeclarativeIMAttributeExtension::actionKeyIconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
