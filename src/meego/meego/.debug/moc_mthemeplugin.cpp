/****************************************************************************
** Meta object code from reading C++ file 'mthemeplugin.h'
**
** Created: Mon Aug 27 22:50:23 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mthemeplugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mthemeplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MThemePlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      32,   13,   13,   13, 0x05,
      53,   13,   13,   13, 0x05,
      74,   13,   13,   13, 0x05,

 // properties: name, type, flags
     103,   98, 0x01495903,
     120,  112, 0x0a495903,
     132,  112, 0x0a495801,
     144,  112, 0x0a495801,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

static const char qt_meta_stringdata_MThemePlugin[] = {
    "MThemePlugin\0\0invertedChanged()\0"
    "colorSchemeChanged()\0colorStringChanged()\0"
    "selectionColorChanged()\0bool\0inverted\0"
    "QString\0colorScheme\0colorString\0"
    "selectionColor\0"
};

void MThemePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MThemePlugin *_t = static_cast<MThemePlugin *>(_o);
        switch (_id) {
        case 0: _t->invertedChanged(); break;
        case 1: _t->colorSchemeChanged(); break;
        case 2: _t->colorStringChanged(); break;
        case 3: _t->selectionColorChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MThemePlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MThemePlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MThemePlugin,
      qt_meta_data_MThemePlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MThemePlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MThemePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MThemePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MThemePlugin))
        return static_cast<void*>(const_cast< MThemePlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int MThemePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< bool*>(_v) = isInverted(); break;
        case 1: *reinterpret_cast< QString*>(_v) = colorScheme(); break;
        case 2: *reinterpret_cast< QString*>(_v) = colorString(); break;
        case 3: *reinterpret_cast< QString*>(_v) = selectionColor(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setInverted(*reinterpret_cast< bool*>(_v)); break;
        case 1: setColorScheme(*reinterpret_cast< QString*>(_v)); break;
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
void MThemePlugin::invertedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MThemePlugin::colorSchemeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MThemePlugin::colorStringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MThemePlugin::selectionColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
