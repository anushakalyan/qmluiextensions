/****************************************************************************
** Meta object code from reading C++ file 'mdeclarativestatusbar.h'
**
** Created: Mon Aug 27 22:52:46 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdeclarativestatusbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdeclarativestatusbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDeclarativeStatusBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   22,   22,   22, 0x0a,
      77,   22,   22,   22, 0x08,
     102,   22,   22,   22, 0x0a,
     124,   22,   22,   22, 0x0a,
     152,  147,   22,   22, 0x0a,
     205,   22,   22,   22, 0x0a,
     234,   22,   22,   22, 0x0a,

 // properties: name, type, flags
     296,  264, 0x0049510b,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeStatusBar[] = {
    "MDeclarativeStatusBar\0\0orientationChanged()\0"
    "updateXdamageEventSubscription()\0"
    "disablePressedFeedback()\0enablePixmapUpdates()\0"
    "disablePixmapUpdates()\0call\0"
    "sharedPixmapHandleReceived(QDBusPendingCallWatcher*)\0"
    "handlePixmapProviderOnline()\0"
    "handlePixmapProviderOffline()\0"
    "MDeclarativeScreen::Orientation\0"
    "orientation\0"
};

void MDeclarativeStatusBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDeclarativeStatusBar *_t = static_cast<MDeclarativeStatusBar *>(_o);
        switch (_id) {
        case 0: _t->orientationChanged(); break;
        case 1: _t->updateXdamageEventSubscription(); break;
        case 2: _t->disablePressedFeedback(); break;
        case 3: _t->enablePixmapUpdates(); break;
        case 4: _t->disablePixmapUpdates(); break;
        case 5: _t->sharedPixmapHandleReceived((*reinterpret_cast< QDBusPendingCallWatcher*(*)>(_a[1]))); break;
        case 6: _t->handlePixmapProviderOnline(); break;
        case 7: _t->handlePixmapProviderOffline(); break;
        default: ;
        }
    }
}

#ifdef Q_NO_DATA_RELOCATION
static const QMetaObjectAccessor qt_meta_extradata_MDeclarativeStatusBar[] = {
        MDeclarativeScreen::getStaticMetaObject,
#else
static const QMetaObject *qt_meta_extradata_MDeclarativeStatusBar[] = {
        &MDeclarativeScreen::staticMetaObject,
#endif //Q_NO_DATA_RELOCATION
    0
};

const QMetaObjectExtraData MDeclarativeStatusBar::staticMetaObjectExtraData = {
    qt_meta_extradata_MDeclarativeStatusBar,  qt_static_metacall 
};

const QMetaObject MDeclarativeStatusBar::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MDeclarativeStatusBar,
      qt_meta_data_MDeclarativeStatusBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeStatusBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeStatusBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeStatusBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeStatusBar))
        return static_cast<void*>(const_cast< MDeclarativeStatusBar*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MDeclarativeStatusBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< MDeclarativeScreen::Orientation*>(_v) = orientation(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOrientation(*reinterpret_cast< MDeclarativeScreen::Orientation*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MDeclarativeStatusBar::orientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
