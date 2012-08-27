/****************************************************************************
** Meta object code from reading C++ file 'mdeclarativescreen.h'
**
** Created: Mon Aug 27 22:51:55 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdeclarativescreen.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdeclarativescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MDeclarativeScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
      20,  114, // properties
       6,  194, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      48,   19,   19,   19, 0x05,
      77,   19,   19,   19, 0x05,
     104,   19,   19,   19, 0x05,
     121,   19,   19,   19, 0x05,
     140,   19,   19,   19, 0x05,
     162,   19,   19,   19, 0x05,
     179,   19,   19,   19, 0x05,
     194,   19,   19,   19, 0x05,
     210,   19,   19,   19, 0x05,
     230,   19,   19,   19, 0x05,
     250,   19,   19,   19, 0x05,
     273,   19,   19,   19, 0x05,
     297,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     334,  322,   19,   19, 0x0a,
     371,   19,   19,   19, 0x08,
     393,   19,   19,   19, 0x08,
     421,   19,   19,   19, 0x08,
     446,   19,   19,   19, 0x08,

 // methods: signature, parameters, type, tag, flags
     484,  474,   19,   19, 0x02,

 // properties: name, type, flags
     543,  531, 0x00495809,
     575,  562, 0x0049590b,
     603,  595, 0x0a495801,
     626,  621, 0x01495801,
     634,  621, 0x01495801,
     651,  647, 0x02495801,
     657,  647, 0x02495801,
     664,  647, 0x02495001,
     677,  647, 0x02495001,
     691,  647, 0x02495801,
     710,  700, 0x00495809,
     728,  621, 0x01495903,
     738,  621, 0x01495903,
     749,  621, 0x01495801,
     766,  760, ((uint)QMetaType::QReal << 24) | 0x00495801,
     786,  770, 0x00495809,
     810,  802, 0x00495809,
     818,  647, 0x02495801,
     832,  647, 0x02495801,
     847,  621, 0x01495801,

 // properties: notify_signal_id
       0,
       1,
       0,
       3,
       5,
       7,
       8,
       6,
       6,
       0,
       2,
       4,
       9,
       0,
       6,
       6,
       6,
      11,
      12,
      13,

 // enums: name, flags, count, data
     531, 0x0,    6,  218,
     562, 0x1,    6,  230,
     700, 0x0,    3,  242,
     866, 0x0,    4,  248,
     770, 0x0,    4,  256,
     802, 0x0,    4,  264,

 // enum data: key, value
     883, uint(MDeclarativeScreen::Default),
     891, uint(MDeclarativeScreen::Portrait),
     900, uint(MDeclarativeScreen::Landscape),
     910, uint(MDeclarativeScreen::PortraitInverted),
     927, uint(MDeclarativeScreen::LandscapeInverted),
     945, uint(MDeclarativeScreen::All),
     883, uint(MDeclarativeScreen::Default),
     891, uint(MDeclarativeScreen::Portrait),
     900, uint(MDeclarativeScreen::Landscape),
     910, uint(MDeclarativeScreen::PortraitInverted),
     927, uint(MDeclarativeScreen::LandscapeInverted),
     945, uint(MDeclarativeScreen::All),
     949, uint(MDeclarativeScreen::Clockwise),
     959, uint(MDeclarativeScreen::NoDirection),
     971, uint(MDeclarativeScreen::CounterClockwise),
     988, uint(MDeclarativeScreen::PortraitAngle),
    1002, uint(MDeclarativeScreen::LandscapeAngle),
    1017, uint(MDeclarativeScreen::PortraitInvertedAngle),
    1039, uint(MDeclarativeScreen::LandscapeInvertedAngle),
    1062, uint(MDeclarativeScreen::Small),
    1068, uint(MDeclarativeScreen::Normal),
    1075, uint(MDeclarativeScreen::Large),
    1081, uint(MDeclarativeScreen::ExtraLarge),
    1092, uint(MDeclarativeScreen::Low),
    1096, uint(MDeclarativeScreen::Medium),
    1103, uint(MDeclarativeScreen::High),
    1108, uint(MDeclarativeScreen::ExtraHigh),

       0        // eod
};

static const char qt_meta_stringdata_MDeclarativeScreen[] = {
    "MDeclarativeScreen\0\0currentOrientationChanged()\0"
    "allowedOrientationsChanged()\0"
    "rotationDirectionChanged()\0coveredChanged()\0"
    "minimizedChanged()\0keyboardOpenChanged()\0"
    "displayChanged()\0widthChanged()\0"
    "heightChanged()\0allowSwipeChanged()\0"
    "isPortraitChanged()\0platformWidthChanged()\0"
    "platformHeightChanged()\0"
    "physicalDisplayChanged()\0orientation\0"
    "setAllowedOrientations(Orientations)\0"
    "_q_isCoveredChanged()\0_q_updateOrientationAngle()\0"
    "_q_updateIsTvConnected()\0"
    "_q_windowAnimationChanged()\0statusBar\0"
    "updatePlatformStatusBarRect(QDeclarativeItem*)\0"
    "Orientation\0currentOrientation\0"
    "Orientations\0allowedOrientations\0"
    "QString\0orientationString\0bool\0covered\0"
    "keyboardOpen\0int\0width\0height\0"
    "displayWidth\0displayHeight\0rotation\0"
    "Direction\0rotationDirection\0minimized\0"
    "allowSwipe\0isPortrait\0qreal\0dpi\0"
    "DisplayCategory\0displayCategory\0Density\0"
    "density\0platformWidth\0platformHeight\0"
    "isDisplayLandscape\0OrientationAngle\0"
    "Default\0Portrait\0Landscape\0PortraitInverted\0"
    "LandscapeInverted\0All\0Clockwise\0"
    "NoDirection\0CounterClockwise\0PortraitAngle\0"
    "LandscapeAngle\0PortraitInvertedAngle\0"
    "LandscapeInvertedAngle\0Small\0Normal\0"
    "Large\0ExtraLarge\0Low\0Medium\0High\0"
    "ExtraHigh\0"
};

void MDeclarativeScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MDeclarativeScreen *_t = static_cast<MDeclarativeScreen *>(_o);
        switch (_id) {
        case 0: _t->currentOrientationChanged(); break;
        case 1: _t->allowedOrientationsChanged(); break;
        case 2: _t->rotationDirectionChanged(); break;
        case 3: _t->coveredChanged(); break;
        case 4: _t->minimizedChanged(); break;
        case 5: _t->keyboardOpenChanged(); break;
        case 6: _t->displayChanged(); break;
        case 7: _t->widthChanged(); break;
        case 8: _t->heightChanged(); break;
        case 9: _t->allowSwipeChanged(); break;
        case 10: _t->isPortraitChanged(); break;
        case 11: _t->platformWidthChanged(); break;
        case 12: _t->platformHeightChanged(); break;
        case 13: _t->physicalDisplayChanged(); break;
        case 14: _t->setAllowedOrientations((*reinterpret_cast< Orientations(*)>(_a[1]))); break;
        case 15: _t->d->_q_isCoveredChanged(); break;
        case 16: _t->d->_q_updateOrientationAngle(); break;
        case 17: _t->d->_q_updateIsTvConnected(); break;
        case 18: _t->d->_q_windowAnimationChanged(); break;
        case 19: _t->updatePlatformStatusBarRect((*reinterpret_cast< QDeclarativeItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MDeclarativeScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MDeclarativeScreen::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MDeclarativeScreen,
      qt_meta_data_MDeclarativeScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MDeclarativeScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MDeclarativeScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MDeclarativeScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MDeclarativeScreen))
        return static_cast<void*>(const_cast< MDeclarativeScreen*>(this));
    return QObject::qt_metacast(_clname);
}

int MDeclarativeScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Orientation*>(_v) = currentOrientation(); break;
        case 1: *reinterpret_cast<int*>(_v) = QFlag(allowedOrientations()); break;
        case 2: *reinterpret_cast< QString*>(_v) = orientationString(); break;
        case 3: *reinterpret_cast< bool*>(_v) = isCovered(); break;
        case 4: *reinterpret_cast< bool*>(_v) = isKeyboardOpen(); break;
        case 5: *reinterpret_cast< int*>(_v) = width(); break;
        case 6: *reinterpret_cast< int*>(_v) = height(); break;
        case 7: *reinterpret_cast< int*>(_v) = displayWidth(); break;
        case 8: *reinterpret_cast< int*>(_v) = displayHeight(); break;
        case 9: *reinterpret_cast< int*>(_v) = rotation(); break;
        case 10: *reinterpret_cast< Direction*>(_v) = rotationDirection(); break;
        case 11: *reinterpret_cast< bool*>(_v) = isMinimized(); break;
        case 12: *reinterpret_cast< bool*>(_v) = allowSwipe(); break;
        case 13: *reinterpret_cast< bool*>(_v) = isPortrait(); break;
        case 14: *reinterpret_cast< qreal*>(_v) = dpi(); break;
        case 15: *reinterpret_cast< DisplayCategory*>(_v) = displayCategory(); break;
        case 16: *reinterpret_cast< Density*>(_v) = density(); break;
        case 17: *reinterpret_cast< int*>(_v) = platformWidth(); break;
        case 18: *reinterpret_cast< int*>(_v) = platformHeight(); break;
        case 19: *reinterpret_cast< bool*>(_v) = isDisplayLandscape(); break;
        }
        _id -= 20;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setAllowedOrientations(QFlag(*reinterpret_cast<int*>(_v))); break;
        case 11: setMinimized(*reinterpret_cast< bool*>(_v)); break;
        case 12: setAllowSwipe(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 20;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 20;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MDeclarativeScreen::currentOrientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MDeclarativeScreen::allowedOrientationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MDeclarativeScreen::rotationDirectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MDeclarativeScreen::coveredChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MDeclarativeScreen::minimizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MDeclarativeScreen::keyboardOpenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MDeclarativeScreen::displayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MDeclarativeScreen::widthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MDeclarativeScreen::heightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void MDeclarativeScreen::allowSwipeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void MDeclarativeScreen::isPortraitChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void MDeclarativeScreen::platformWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void MDeclarativeScreen::platformHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void MDeclarativeScreen::physicalDisplayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}
QT_END_MOC_NAMESPACE
