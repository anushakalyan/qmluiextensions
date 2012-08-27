/****************************************************************************
** Meta object code from reading C++ file 'mscrolldecoratorsizer.h'
**
** Created: Mon Aug 27 22:52:11 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mscrolldecoratorsizer.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mscrolldecoratorsizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MScrollDecoratorSizer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       6,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      46,   22,   22,   22, 0x05,
      65,   22,   22,   22, 0x05,
      86,   22,   22,   22, 0x05,
     103,   22,   22,   22, 0x05,
     121,   22,   22,   22, 0x05,

 // properties: name, type, flags
     141,  135, ((uint)QMetaType::QReal << 24) | 0x00495103,
     155,  135, ((uint)QMetaType::QReal << 24) | 0x00495103,
     165,  135, ((uint)QMetaType::QReal << 24) | 0x00495103,
     177,  135, ((uint)QMetaType::QReal << 24) | 0x00495103,
     189,  185, 0x02495801,
     198,  185, 0x02495801,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

static const char qt_meta_stringdata_MScrollDecoratorSizer[] = {
    "MScrollDecoratorSizer\0\0positionRatioChanged()\0"
    "sizeRatioChanged()\0maxPositionChanged()\0"
    "minSizeChanged()\0positionChanged()\0"
    "sizeChanged()\0qreal\0positionRatio\0"
    "sizeRatio\0maxPosition\0minSize\0int\0"
    "position\0size\0"
};

void MScrollDecoratorSizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MScrollDecoratorSizer *_t = static_cast<MScrollDecoratorSizer *>(_o);
        switch (_id) {
        case 0: _t->positionRatioChanged(); break;
        case 1: _t->sizeRatioChanged(); break;
        case 2: _t->maxPositionChanged(); break;
        case 3: _t->minSizeChanged(); break;
        case 4: _t->positionChanged(); break;
        case 5: _t->sizeChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MScrollDecoratorSizer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MScrollDecoratorSizer::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MScrollDecoratorSizer,
      qt_meta_data_MScrollDecoratorSizer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MScrollDecoratorSizer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MScrollDecoratorSizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MScrollDecoratorSizer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MScrollDecoratorSizer))
        return static_cast<void*>(const_cast< MScrollDecoratorSizer*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MScrollDecoratorSizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = positionRatio(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = sizeRatio(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = maxPosition(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = minSize(); break;
        case 4: *reinterpret_cast< int*>(_v) = position(); break;
        case 5: *reinterpret_cast< int*>(_v) = size(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPositionRatio(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setSizeRatio(*reinterpret_cast< qreal*>(_v)); break;
        case 2: setMaxPosition(*reinterpret_cast< qreal*>(_v)); break;
        case 3: setMinSize(*reinterpret_cast< qreal*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MScrollDecoratorSizer::positionRatioChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MScrollDecoratorSizer::sizeRatioChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MScrollDecoratorSizer::maxPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MScrollDecoratorSizer::minSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MScrollDecoratorSizer::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MScrollDecoratorSizer::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
