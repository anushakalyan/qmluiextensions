/****************************************************************************
** Meta object code from reading C++ file 'mremotethemedaemonclient.h'
**
** Created: Mon Aug 27 22:52:23 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../themedaemon/mremotethemedaemonclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mremotethemedaemonclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MRemoteThemeDaemonClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MRemoteThemeDaemonClient[] = {
    "MRemoteThemeDaemonClient\0\0"
    "connectionDataAvailable()\0"
};

void MRemoteThemeDaemonClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MRemoteThemeDaemonClient *_t = static_cast<MRemoteThemeDaemonClient *>(_o);
        switch (_id) {
        case 0: _t->connectionDataAvailable(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MRemoteThemeDaemonClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MRemoteThemeDaemonClient::staticMetaObject = {
    { &MAbstractThemeDaemonClient::staticMetaObject, qt_meta_stringdata_MRemoteThemeDaemonClient,
      qt_meta_data_MRemoteThemeDaemonClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MRemoteThemeDaemonClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MRemoteThemeDaemonClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MRemoteThemeDaemonClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MRemoteThemeDaemonClient))
        return static_cast<void*>(const_cast< MRemoteThemeDaemonClient*>(this));
    return MAbstractThemeDaemonClient::qt_metacast(_clname);
}

int MRemoteThemeDaemonClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MAbstractThemeDaemonClient::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
