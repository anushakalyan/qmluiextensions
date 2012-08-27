/****************************************************************************
** Meta object code from reading C++ file 'mdatetimehelper.h'
**
** Created: Mon Aug 27 22:53:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdatetimehelper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdatetimehelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDateTimeHelper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       2,   49, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      31,   25,   17,   16, 0x02,
      61,   56,   51,   16, 0x02,
      92,   81,   77,   16, 0x02,
     113,   16,   77,   16, 0x02,
     127,   16,   17,   16, 0x02,
     136,   16,   17,   16, 0x02,
     145,   16,   77,   16, 0x02,

 // enums: name, flags, count, data
     156, 0x0,    4,   57,
     165, 0x0,    2,   65,

 // enum data: key, value
     174, uint(MDateTimeHelper::Hours),
     180, uint(MDateTimeHelper::Minutes),
     188, uint(MDateTimeHelper::Seconds),
     196, uint(MDateTimeHelper::All),
     200, uint(MDateTimeHelper::TwelveHours),
     212, uint(MDateTimeHelper::TwentyFourHours),

       0        // eod
};

static const char qt_meta_stringdata_MDateTimeHelper[] = {
    "MDateTimeHelper\0\0QString\0month\0"
    "shortMonthName(int)\0bool\0year\0"
    "isLeapYear(int)\0int\0year,month\0"
    "daysInMonth(int,int)\0currentYear()\0"
    "amText()\0pmText()\0hourMode()\0TimeUnit\0"
    "HourMode\0Hours\0Minutes\0Seconds\0All\0"
    "TwelveHours\0TwentyFourHours\0"
};

void MDateTimeHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDateTimeHelper *_t = static_cast<MDateTimeHelper *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->shortMonthName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->isLeapYear((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->daysInMonth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->currentYear();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->amText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->pmText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->hourMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MDateTimeHelper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDateTimeHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MDateTimeHelper,
      qt_meta_data_MDateTimeHelper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDateTimeHelper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDateTimeHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDateTimeHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDateTimeHelper))
        return static_cast<void*>(const_cast< MDateTimeHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int MDateTimeHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
