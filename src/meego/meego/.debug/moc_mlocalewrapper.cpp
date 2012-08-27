/****************************************************************************
** Meta object code from reading C++ file 'mlocalewrapper.h'
**
** Created: Mon Aug 27 22:52:38 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../i18n/mlocalewrapper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mlocalewrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MLocaleWrapper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       7,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
      15, 0x0,    6,   42,
      24, 0x0,    5,   54,
      33, 0x0,    7,   64,
      42, 0x0,    9,   78,
      52, 0x0,   11,   96,
      65, 0x0,    3,  118,
      79, 0x0,    7,  124,

 // enum data: key, value
      87, uint(MLocaleWrapper::DateNone),
      96, uint(MLocaleWrapper::DateShort),
     106, uint(MLocaleWrapper::DateMedium),
     117, uint(MLocaleWrapper::DateLong),
     126, uint(MLocaleWrapper::DateFull),
     135, uint(MLocaleWrapper::DateYearAndMonth),
     152, uint(MLocaleWrapper::TimeNone),
     161, uint(MLocaleWrapper::TimeShort),
     171, uint(MLocaleWrapper::TimeMedium),
     182, uint(MLocaleWrapper::TimeLong),
     191, uint(MLocaleWrapper::TimeFull),
     200, uint(MLocaleWrapper::MLcMessages),
     212, uint(MLocaleWrapper::MLcTime),
     220, uint(MLocaleWrapper::MLcCollate),
     231, uint(MLocaleWrapper::MLcNumeric),
     242, uint(MLocaleWrapper::MLcMonetary),
     254, uint(MLocaleWrapper::MLcName),
     262, uint(MLocaleWrapper::MLcTelephone),
     275, uint(MLocaleWrapper::DefaultCollation),
     292, uint(MLocaleWrapper::PhonebookCollation),
     311, uint(MLocaleWrapper::PinyinCollation),
     327, uint(MLocaleWrapper::TraditionalCollation),
     348, uint(MLocaleWrapper::StrokeCollation),
     364, uint(MLocaleWrapper::DirectCollation),
     380, uint(MLocaleWrapper::PosixCollation),
     395, uint(MLocaleWrapper::Big5hanCollation),
     412, uint(MLocaleWrapper::Gb2312hanCollation),
     431, uint(MLocaleWrapper::DefaultCalendar),
     447, uint(MLocaleWrapper::GregorianCalendar),
     465, uint(MLocaleWrapper::IslamicCalendar),
     481, uint(MLocaleWrapper::ChineseCalendar),
     497, uint(MLocaleWrapper::IslamicCivilCalendar),
     518, uint(MLocaleWrapper::HebrewCalendar),
     533, uint(MLocaleWrapper::JapaneseCalendar),
     550, uint(MLocaleWrapper::BuddhistCalendar),
     567, uint(MLocaleWrapper::PersianCalendar),
     583, uint(MLocaleWrapper::CopticCalendar),
     598, uint(MLocaleWrapper::EthiopicCalendar),
     615, uint(MLocaleWrapper::LocaleDefaultTimeFormat24h),
     642, uint(MLocaleWrapper::TwelveHourTimeFormat24h),
     666, uint(MLocaleWrapper::TwentyFourHourTimeFormat24h),
     694, uint(MLocaleWrapper::Monday),
     701, uint(MLocaleWrapper::Tuesday),
     709, uint(MLocaleWrapper::Wednesday),
     719, uint(MLocaleWrapper::Thursday),
     728, uint(MLocaleWrapper::Friday),
     735, uint(MLocaleWrapper::Saturday),
     744, uint(MLocaleWrapper::Sunday),

       0        // eod
};

static const char qt_meta_stringdata_MLocaleWrapper[] = {
    "MLocaleWrapper\0DateType\0TimeType\0"
    "Category\0Collation\0CalendarType\0"
    "TimeFormat24h\0Weekday\0DateNone\0DateShort\0"
    "DateMedium\0DateLong\0DateFull\0"
    "DateYearAndMonth\0TimeNone\0TimeShort\0"
    "TimeMedium\0TimeLong\0TimeFull\0MLcMessages\0"
    "MLcTime\0MLcCollate\0MLcNumeric\0MLcMonetary\0"
    "MLcName\0MLcTelephone\0DefaultCollation\0"
    "PhonebookCollation\0PinyinCollation\0"
    "TraditionalCollation\0StrokeCollation\0"
    "DirectCollation\0PosixCollation\0"
    "Big5hanCollation\0Gb2312hanCollation\0"
    "DefaultCalendar\0GregorianCalendar\0"
    "IslamicCalendar\0ChineseCalendar\0"
    "IslamicCivilCalendar\0HebrewCalendar\0"
    "JapaneseCalendar\0BuddhistCalendar\0"
    "PersianCalendar\0CopticCalendar\0"
    "EthiopicCalendar\0LocaleDefaultTimeFormat24h\0"
    "TwelveHourTimeFormat24h\0"
    "TwentyFourHourTimeFormat24h\0Monday\0"
    "Tuesday\0Wednesday\0Thursday\0Friday\0"
    "Saturday\0Sunday\0"
};

void MLocaleWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MLocaleWrapper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MLocaleWrapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MLocaleWrapper,
      qt_meta_data_MLocaleWrapper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MLocaleWrapper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MLocaleWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MLocaleWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MLocaleWrapper))
        return static_cast<void*>(const_cast< MLocaleWrapper*>(this));
    return QObject::qt_metacast(_clname);
}

int MLocaleWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
