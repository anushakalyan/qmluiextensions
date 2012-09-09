include (../qmluiextensions.pri)
symbian3 { TARGETPATH = QmlUiExtensions }
else { TARGETPATH = QmlUiExtensions }
TEMPLATE = lib
TARGET = $$qtLibraryTarget(QmlUiExtensionsPlugin)
INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/compatinclude

win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
CONFIG += qt plugin
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += qml quick widgets network
    OTHER_FILES += QmlUiExtensionsPlugin.json
} else {
    QT += declarative opengl network
}
RESOURCES += \
    qmluiextensions.qrc

!win32:!macx: QT += dbus

!win32:!embedded:!mac:!symbian {
    CONFIG += link_pkgconfig
}

meegotouch {
    DEFINES += HAVE_MEEGOTOUCH
}

maliit {
    DEFINES += HAVE_MALIIT
    PKGCONFIG += maliit-1.0
}

contains(DEFINES, HAVE_MEEGOGRAPHICSSYSTEM) {
    QT += meegographicssystemhelper
}

contains(DEFINES, HAVE_THEMEDAEMON_PROTOCOL_V1) {
    DEFINES += HAVE_THEMEDAEMON_PROTOCOL_V1
}

themedaemonprotocolv1 {
    DEFINES += HAVE_THEMEDAEMON_PROTOCOL_V1
}

meegographicssystem {
    DEFINES += HAVE_MEEGOGRAPHICSSYSTEM
    QT += meegographicssystemhelper
}

xdamage {
    DEFINES += HAVE_XDAMAGE
    PKGCONFIG += xdamage
}

xrandr:!mac {
    DEFINES += HAVE_XRANDR
    LIBS += -lXrandr
}

load(mobilityconfig, true)
contains(MOBILITY_CONFIG, systeminfo) {
    CONFIG += mobility
    MOBILITY += systeminfo
    DEFINES += HAVE_SYSTEMINFO
}

contains(QT_CONFIG, dbus): DEFINES += HAVE_DBUS

contains(QT_CONFIG, opengles2): CONFIG += egl

contains(QT_CONFIG, xlib): DEFINES += HAVE_XLIB
DEFINES += HAVE_XLIB

DEFINES += QT_BUILD_COMPONENTS_LIB

QML_FILES = \
        qmldir \
        style/core/TextStyle.qml \
        style/core/Style.qml \
        style/default/ApplicationWindowStyle.qml \
        style/default/BusyIndicatorStyle.qml \
        style/default/ButtonStyle.qml \
        style/default/GroupButtonStyle.qml \
        style/default/CheckBoxStyle.qml \
        style/default/ContextMenuStyle.qml \
        style/default/EditBubbleStyle.qml \
        style/default/EditBubbleButtonStyle.qml \
        style/default/DialogStyle.qml \
        style/default/QueryDialogStyle.qml \
        style/default/SelectionDialogStyle.qml \
        style/default/MenuStyle.qml \
        style/default/LabelStyle.qml \
        style/default/ListDelegateStyle.qml \
        style/default/MenuItemStyle.qml \
        style/default/PageStackWindowStyle.qml \
        style/default/ProgressBarStyle.qml \
        style/default/RadioButtonStyle.qml \
        style/default/SectionScrollerStyle.qml \
        style/default/ScrollDecoratorStyle.qml \
        style/default/SelectionHandlesStyle.qml \
        style/default/TextAreaStyle.qml \
        style/default/TextFieldStyle.qml \
        style/default/TabButtonStyle.qml \
        style/default/ToolBarStyle.qml \
        style/default/ToolButtonStyle.qml \
        style/default/ToolItemStyle.qml \
        style/default/SheetStyle.qml \
        style/default/SheetButtonStyle.qml \
        style/default/SheetButtonAccentStyle.qml \
        style/default/SliderStyle.qml \
        style/default/SwitchStyle.qml \
        style/default/ListButtonStyle.qml \
        style/default/NegativeButtonStyle.qml \
        style/default/PositiveButtonStyle.qml \
        style/default/TumblerButtonStyle.qml \
        gui/components/BusyIndicator.qml \
        gui/components/Button.qml \
        gui/components/ButtonColumn.qml \
        gui/components/ButtonRow.qml \
        gui/components/ButtonGroup.js \
        gui/components/BasicRow.qml \
        gui/components/BasicRow.js \
        gui/components/CheckBox.qml \
        gui/components/CommonDialog.qml \
        gui/components/ContextMenu.qml \
        gui/components/Dialog.qml \
        gui/components/Utils.js \
        gui/components/EditBubble.js \
        gui/components/EditBubble.qml \
        gui/components/EditBubbleButton.qml \
        gui/components/Fader.qml \
        gui/components/Label.qml \
        gui/components/AbstractMenu.qml \
        gui/components/Menu.qml \
        gui/components/MenuItem.qml \
        gui/components/MenuLayout.qml \
        gui/components/MouseAreaDebug.qml \
        gui/components/NotificationBanner.qml \
        gui/components/Page.qml \
        gui/components/PageStack.qml \
        gui/components/PageStack.js \
        gui/components/PageStackWindow.qml \
        gui/components/Popup.qml \
        gui/components/QueryDialog.qml \
        gui/components/SelectionDialog.qml \
        gui/components/MultiSelectionDialog.qml \
        gui/components/ProgressBar.qml \
        gui/components/RadioButton.qml \
        gui/components/ScrollDecorator.qml \
        gui/components/ScrollDecoratorSizer.qml \
        gui/components/SectionScroller.qml \
        gui/components/SectionScroller.js \
        gui/components/SectionScrollerLabel.qml \
        gui/components/SelectionHandles.qml \
        gui/components/SelectionHandles.js \
        gui/components/StatusBar.qml \
        gui/components/TextArea.qml \
        gui/components/TabButton.qml \
        gui/components/TabBarLayout.qml \
        gui/components/TabGroup.qml \
        gui/components/ToolBar.qml \
        gui/components/ToolBarLayout.js \
        gui/components/ToolBarLayout.qml \
        gui/components/ToolButton.qml \
        gui/components/ToolItem.qml \
        gui/components/ToolIcon.qml \
        gui/components/ToolButtonRow.qml \
        gui/components/Sheet.qml \
        gui/components/SheetButton.qml \
        gui/components/Slider.qml \
        gui/components/SliderTemplate.qml \
        gui/components/Switch.qml \
        gui/components/UIConstants.js \
        gui/components/Window.qml \
        gui/components/SipSimulator.qml \
        gui/components/SoftwareInputPanel.qml \
        gui/components/TextAreaHelper.js \
        gui/components/MultiSelectionDialog.js \
        gui/components/Magnifier.qml \
        gui/components/Magnifier.js \
        gui/components/constants.js\
        gui/components/CountBubble.qml \
        gui/components/DatePickerDialog.qml \
        gui/components/InfoBanner.qml \
        gui/components/ListDelegate.qml \
        gui/components/ListButton.qml \
        gui/components/MoreIndicator.qml \
        gui/components/NetPromoterScore.qml \
        gui/components/PageIndicator.qml \
        gui/components/RatingIndicator.qml \
        gui/components/SystemBanner.qml \
        gui/components/TimePickerDialog.qml \
        gui/components/Tumbler.qml \
        gui/components/Tumbler.js \
        gui/components/TumblerColumn.qml \
        gui/components/TumblerIndexHelper.js \
        gui/components/TumblerTemplate.qml \
        gui/components/TumblerButton.qml \
        gui/components/TumblerDialog.qml \
        gui/components/Checkable.qml \
        gui/components/CheckableGroup.qml \
        gui/components/CheckableGroup.js

greaterThan(QT_MAJOR_VERSION, 4) {
# Tweaks sources and headers for Qt5
QML_FILES += \
    gui/components/MaskedItem.qml \
    gui/components/compat/TextField.qml
}

!greaterThan(QT_MAJOR_VERSION, 4) {
# Tweaks sources and headers for Qt5
QML_FILES += \
    gui/components/TextField.qml \
    gui/components/Snapshot.qml
}

symbian {
    TARGET.EPOCALLOWDLLDATA = 1
    TARGET.CAPABILITY = ALL -TCB
    TARGET.UID3 = 0x2003DF67
    MMP_RULES += SMPSAFE
    VERSION = 10.1.2

    vendor_info = \
            " " \
            "; Localised Vendor name" \
            "%{\"Nokia\"}" \
            " " \
            "; Unique Vendor name" \
            ":\"Nokia\"" \
            " "

    package.pkg_prerules += vendor_info
    DEPLOYMENT += package

    defBlock = \
        "$${LITERAL_HASH}ifdef WINSCW" \
        "DEFFILE  bwins/components.def" \
        "$${LITERAL_HASH}elif defined EABI" \
        "DEFFILE  eabi/components.def" \
        "$${LITERAL_HASH}endif"
    MMP_RULES += defBlock
}

SOURCES += plugin.cpp

include(compatinclude/compatinclude.pri)
include(core/core.pri)
include(platform/platform.pri)
include(gui/gui.pri)
include(feedback/feedback.pri)
include(i18n/i18n.pri)
!greaterThan(QT_MAJOR_VERSION, 4) {
include(shadereffectitem/shadereffectitem.pri)
}
include(style/style.pri)
include(themedaemon/themedaemon.pri)
include(../qml.pri)


