/****************************************************************************
** Meta object code from reading C++ file 'mdeclarativeinputcontext.h'
**
** Created: Mon Aug 27 22:50:57 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdeclarativeinputcontext.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdeclarativeinputcontext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDeclarativeInputContext[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       7,   99, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x05,
      61,   25,   25,   25, 0x05,
      93,   25,   25,   25, 0x05,
     112,   25,   25,   25, 0x05,
     132,   25,   25,   25, 0x05,
     165,   25,   25,   25, 0x05,
     208,   25,   25,   25, 0x05,
     249,   25,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
     292,   25,   25,   25, 0x08,

 // methods: signature, parameters, type, tag, flags
     313,   25,   25,   25, 0x02,
     332,   25,   25,   25, 0x02,
     340,   25,   25,   25, 0x02,
     420,  354,  349,   25, 0x02,
     508,  474,  456,   25, 0x02,
     547,   25,   25,   25, 0x02,
     565,   25,   25,   25, 0x02,
     584,   25,   25,   25, 0x02,

 // properties: name, type, flags
     601,  349, 0x01495801,
     633,  627, 0x13495801,
     663,  656, 0x14495001,
     683,  674, 0xff495103,
     474,  707, 0x0049510b,
     730,  456, 0x0009510a,
     764,  349, 0x01495103,

 // properties: notify_signal_id
       0,
       1,
       3,
       4,
       5,
       0,
       6,

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeInputContext[] = {
    "MDeclarativeInputContext\0\0"
    "softwareInputPanelVisibleChanged()\0"
    "softwareInputPanelRectChanged()\0"
    "minimizedChanged()\0microFocusChanged()\0"
    "softwareInputPanelEventChanged()\0"
    "customSoftwareInputPanelComponentChanged()\0"
    "customSoftwareInputPanelVisibleChanged()\0"
    "customSoftwareInputPanelTextFieldChanged()\0"
    "_q_sipChanged(QRect)\0updateMicroFocus()\0"
    "reset()\0update()\0bool\0"
    "newPreedit,eventCursorPosition,replacementStart,replacementLength\0"
    "setPreeditText(QString,int,int,int)\0"
    "QDeclarativeItem*\0customSoftwareInputPanelComponent\0"
    "targetInputFor(QDeclarativeComponent*)\0"
    "simulateSipOpen()\0simulateSipClose()\0"
    "clearClipboard()\0softwareInputPanelVisible\0"
    "QRect\0softwareInputPanelRect\0QRectF\0"
    "microFocus\0QVariant\0softwareInputPanelEvent\0"
    "QDeclarativeComponent*\0"
    "customSoftwareInputPanelTextField\0"
    "customSoftwareInputPanelVisible\0"
};

void MDeclarativeInputContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDeclarativeInputContext *_t = static_cast<MDeclarativeInputContext *>(_o);
        switch (_id) {
        case 0: _t->softwareInputPanelVisibleChanged(); break;
        case 1: _t->softwareInputPanelRectChanged(); break;
        case 2: _t->minimizedChanged(); break;
        case 3: _t->microFocusChanged(); break;
        case 4: _t->softwareInputPanelEventChanged(); break;
        case 5: _t->customSoftwareInputPanelComponentChanged(); break;
        case 6: _t->customSoftwareInputPanelVisibleChanged(); break;
        case 7: _t->customSoftwareInputPanelTextFieldChanged(); break;
        case 8: _t->d->_q_sipChanged((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 9: _t->updateMicroFocus(); break;
        case 10: _t->reset(); break;
        case 11: _t->update(); break;
        case 12: { bool _r = _t->setPreeditText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { QDeclarativeItem* _r = _t->targetInputFor((*reinterpret_cast< QDeclarativeComponent*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDeclarativeItem**>(_a[0]) = _r; }  break;
        case 14: _t->simulateSipOpen(); break;
        case 15: _t->simulateSipClose(); break;
        case 16: _t->clearClipboard(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MDeclarativeInputContext::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDeclarativeInputContext::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MDeclarativeInputContext,
      qt_meta_data_MDeclarativeInputContext, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeInputContext::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeInputContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeInputContext::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeInputContext))
        return static_cast<void*>(const_cast< MDeclarativeInputContext*>(this));
    return QObject::qt_metacast(_clname);
}

int MDeclarativeInputContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = softwareInputPanelVisible(); break;
        case 1: *reinterpret_cast< QRect*>(_v) = softwareInputPanelRect(); break;
        case 2: *reinterpret_cast< QRectF*>(_v) = microFocus(); break;
        case 3: *reinterpret_cast< QVariant*>(_v) = softwareInputPanelEvent(); break;
        case 4: *reinterpret_cast< QDeclarativeComponent**>(_v) = customSoftwareInputPanelComponent(); break;
        case 6: *reinterpret_cast< bool*>(_v) = customSoftwareInputPanelVisible(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 3: setSoftwareInputPanelEvent(*reinterpret_cast< QVariant*>(_v)); break;
        case 4: setCustomSoftwareInputPanelComponent(*reinterpret_cast< QDeclarativeComponent**>(_v)); break;
        case 5: setCustomSoftwareInputPanelTextField(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 6: setCustomSoftwareInputPanelVisible(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MDeclarativeInputContext::softwareInputPanelVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MDeclarativeInputContext::softwareInputPanelRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MDeclarativeInputContext::minimizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MDeclarativeInputContext::microFocusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MDeclarativeInputContext::softwareInputPanelEventChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MDeclarativeInputContext::customSoftwareInputPanelComponentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MDeclarativeInputContext::customSoftwareInputPanelVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MDeclarativeInputContext::customSoftwareInputPanelTextFieldChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
