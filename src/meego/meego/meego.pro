include (../../qt-components.pri)

TARGETPATH = com/nokia/meego com/meego
TEMPLATE = lib
TARGET = $$qtLibraryTarget(meegoplugin)
INCLUDEPATH += $$PWD

DEFINES += THEME_DIR=\\\"\"$$THEME_DIR\"\\\"
force-local-theme: DEFINES+=FORCE_LOCAL_THEME

win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
CONFIG += qt plugin copy_native install_native
QT += network opengl core
greaterThan(QT_MAJOR_VERSION, 4) {
   QT += qml quick widgets
   OTHER_FILES += meegoplugin.json
} else {
   QT += declarative
}
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

contextsubscriber {
    DEFINES += HAVE_CONTEXTSUBSCRIBER
    INCLUDEPATH += /usr/include/contextsubscriber
    LIBS += -lcontextsubscriber
    SOURCES += mservicelistener.cpp
    HEADERS += mservicelistener.h
    # PKGCONFIG += contextsubscriber
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
SOURCES += \
    plugin.cpp \
    mdeclarativestatusbar.cpp \
    minversemousearea.cpp \
    mdeclarativeimageprovider.cpp \
    mdeclarativeimplicitsizeitem.cpp \
    mscrolldecoratorsizer.cpp \
    mtexttranslator.cpp \
    mthemeplugin.cpp \
    mx11wrapper.cpp \
    themedaemon/mabstractthemedaemonclient.cpp \
    themedaemon/mlocalthemedaemonclient.cpp \
    themedaemon/mremotethemedaemonclient.cpp \
    themedaemon/mthemedaemonprotocol.cpp \
    mdeclarativemousefilter.cpp \
    mdeclarativeimattributeextension.cpp \
    mdeclarativeimobserver.cpp \
    feedbackplayer.cpp

HEADERS += \
    mdeclarativestatusbar_bridge.h \
    mdeclarativescreen_bridge.h \
    mdialogstatus.h \
    msnapshot_bridge.h \
    mpagestatus.h \
    minversemousearea.h \
    mdeclarativeinputcontext_bridge.h \
    mdeclarativeimageprovider.h \
    mdeclarativeimplicitsizeitem.h \
    mscrolldecoratorsizer.h \
    mtexttranslator.h \
    mthemeplugin.h \
    mwindowstate_bridge.h \
    mx11wrapper.h \
    themedaemon/mabstractthemedaemonclient.h \
    themedaemon/mlocalthemedaemonclient.h \
    themedaemon/mremotethemedaemonclient.h \
    themedaemon/mthemedaemonprotocol.h \
    mdeclarativemousefilter.h \
    mdeclarativeimattributeextension.h \
    mdeclarativeimobserver.h \
    i18n/mlocalewrapper.h \
    mpageorientation.h \
    mtoolbarvisibility.h \
    feedbackplayer.h
                            

QML_FILES = \
        qmldir \
        style/ApplicationWindowStyle.qml \
        BusyIndicator.qml \
        style/BusyIndicatorStyle.qml \
        Button.qml \
        style/ButtonStyle.qml \
        style/GroupButtonStyle.qml \
        ButtonColumn.qml \
        ButtonRow.qml \
        ButtonGroup.js \
        BasicRow.qml \
        BasicRow.js \
        CheckBox.qml \
        CommonDialog.qml \
        style/CheckBoxStyle.qml \
        ContextMenu.qml \
        style/ContextMenuStyle.qml \
        Dialog.qml \
        Utils.js \
        EditBubble.js \
        EditBubble.qml \
        EditBubbleButton.qml \
        style/EditBubbleStyle.qml \
        style/EditBubbleButtonStyle.qml \
        style/DialogStyle.qml \
        style/QueryDialogStyle.qml \
        style/SelectionDialogStyle.qml \
        style/MenuStyle.qml \
        Fader.qml \
        Label.qml \
        style/LabelStyle.qml \
        AbstractMenu.qml \
        Menu.qml \
        MenuItem.qml \
        MenuLayout.qml \
        style/MenuItemStyle.qml \
        MouseAreaDebug.qml \
        NotificationBanner.qml \
        Page.qml \
        PageStack.qml \
        PageStack.js \
        PageStackWindow.qml \
	style/PageStackWindowStyle.qml \
        Popup.qml \
        QueryDialog.qml \
        SelectionDialog.qml \
        MultiSelectionDialog.qml \
        ProgressBar.qml \
        style/ProgressBarStyle.qml \
        RadioButton.qml \
        style/RadioButtonStyle.qml \
        ScrollDecorator.qml \
        style/ScrollDecoratorStyle.qml \
        ScrollDecoratorSizer.qml \
        SectionScroller.qml \
        style/SectionScrollerStyle.qml \
        SectionScroller.js \
        SectionScrollerLabel.qml \
        SelectionHandles.qml \
        SelectionHandles.js \
        style/SelectionHandlesStyle.qml \
        StatusBar.qml \
        TextArea.qml \
        style/TextAreaStyle.qml \
        TextField.qml \
        style/TextFieldStyle.qml \
        TabButton.qml \
        TabBarLayout.qml \
        style/TabButtonStyle.qml \
        style/Style.qml \
        TabGroup.qml \
        ToolBar.qml \
        ToolBarLayout.js \
        ToolBarLayout.qml \
        style/ToolBarStyle.qml \
        ToolButton.qml \
        style/ToolButtonStyle.qml \
        ToolItem.qml \
        ToolIcon.qml \
        ToolButtonRow.qml \
        style/ToolItemStyle.qml \
        Sheet.qml \
        style/SheetStyle.qml \
        SheetButton.qml \
        style/SheetButtonStyle.qml \
        style/SheetButtonAccentStyle.qml \
        Slider.qml \
        style/SliderStyle.qml \
        SliderTemplate.qml \
        Switch.qml \
        style/SwitchStyle.qml \
        UIConstants.js \
        Window.qml \
        SipSimulator.qml \
        SoftwareInputPanel.qml \
        TextAreaHelper.js \ 
        MultiSelectionDialog.js \
        Magnifier.qml \
        Magnifier.js

greaterThan(QT_MAJOR_VERSION, 4) {
    # Tweaks sources and headers for Qt5
    QT += gui-private

    QML_FILES -= \
        TextField.qml

    QML_FILES += \
        MaskedItem.qml \
        Snapshot.qml \
        ../compat/meego/TextField.qml

    SOURCES += \
        ../compat/meego/mdeclarativeinputcontext.cpp

    HEADERS += \
        ../compat/meego/mdeclarativestatusbar.h \
        ../compat/meego/mdeclarativeinputcontext.h
} else {

    SOURCES += \
        mdeclarativeinputcontext.cpp \
        mdeclarativemaskeditem.cpp \
        mdeclarativeview.cpp \
        msnapshot.cpp \
        shadereffectitem/shadereffect.cpp \
        shadereffectitem/shadereffectitem.cpp \
        shadereffectitem/shadereffectsource.cpp \
        shadereffectitem/shadereffectbuffer.cpp \
        shadereffectitem/scenegraph/qsggeometry.cpp

    HEADERS += \
        mdeclarativestatusbar.h \
        mdeclarativeinputcontext.h \
        mdeclarativemaskeditem.h \
        mdeclarativeview.h \
        msnapshot.h \
        shadereffectitem/glfunctions.h \
        shadereffectitem/shadereffect.h \
        shadereffectitem/shadereffectitem.h \
        shadereffectitem/shadereffectsource.h \
        shadereffectitem/shadereffectbuffer.h \
        shadereffectitem/scenegraph/qsggeometry.h
}

!qmlextensions {
    SOURCES += \
        mwindowstate.cpp \
        mdeclarativescreen.cpp

    HEADERS += \
        mwindowstate_p.h

    greaterThan(QT_MAJOR_VERSION, 4) {
        # Tweaks sources and headers for Qt5
        HEADERS += \
            ../compat/meego/mwindowstate.h \
            ../compat/meego/mdeclarativescreen.h
    } else {
        HEADERS += \
            mwindowstate.h \
            mdeclarativescreen.h
    }
}

qmlextensions {
DEFINES += USE_ABSTRACTION
    HEADERS += \
    ../experimental/QmlUiExtensions/core/qmlwindowstate.h \
    ../experimental/QmlUiExtensions/core/qmlwindowstate_p.h \
    ../experimental/QmlUiExtensions/core/qmlwindoweventhandler.h \
    ../experimental/QmlUiExtensions/core/qmlscreendisplayproperties.h \
    ../experimental/QmlUiExtensions/core/qmlscreendisplayconstants.h

    SOURCES += \
    ../experimental/QmlUiExtensions/core/qmlwindowstate.cpp \
    ../experimental/QmlUiExtensions/core/qmlwindoweventhandler.cpp \
    ../experimental/QmlUiExtensions/platform/meego/qmlwindoweventhandler_x11.cpp \
    ../experimental/QmlUiExtensions/gui/mdeclarativescreen.cpp \
    ../experimental/QmlUiExtensions/core/qmlscreendisplayproperties.cpp
    greaterThan(QT_MAJOR_VERSION, 4) {
        # Tweaks sources and headers for Qt5
        HEADERS += \
           ../experimental/QmlUiExtensions/platform/compat/meego/qmlwindoweventhandler_x11.h \
           ../experimental/QmlUiExtensions/gui/compat/mdeclarativescreen.h
    } else {

        HEADERS += \
           ../experimental/QmlUiExtensions/platform/meego/qmlwindoweventhandler_x11.h \
           ../experimental/QmlUiExtensions/gui/mdeclarativescreen.h
    }
}

include(../../qml.pri)

OTHER_FILES +=
