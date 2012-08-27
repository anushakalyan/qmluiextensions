/****************************************************************************
** Meta object code from reading C++ file 'mtexttranslator.h'
**
** Created: Mon Aug 27 22:52:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mtexttranslator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mtexttranslator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MTextTranslator[] = {

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

 // methods: signature, parameters, type, tag, flags
      32,   25,   17,   16, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_MTextTranslator[] = {
    "MTextTranslator\0\0QString\0textId\0"
    "translate(QString)\0"
};

void MTextTranslator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MTextTranslator *_t = static_cast<MTextTranslator *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->translate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MTextTranslator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MTextTranslator::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_MTextTranslator,
      qt_meta_data_MTextTranslator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MTextTranslator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MTextTranslator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MTextTranslator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MTextTranslator))
        return static_cast<void*>(const_cast< MTextTranslator*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int MTextTranslator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
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
