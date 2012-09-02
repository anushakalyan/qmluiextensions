/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Components project.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QFont>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets/QApplication>
#include <QtQml>
#include <QQmlPropertyMap>
#else
#include <QApplication>
#include <QtDeclarative>
#include <QDeclarativePropertyMap>
#include "mdeclarativeview.h"
#include "shadereffectitem/shadereffectitem.h"
#include "shadereffectitem/shadereffectsource.h"
#include "gui/core/msnapshot.h"
#endif
#include "core/qmlwindowstate.h"
#include "mdeclarativestatusbar_bridge.h"
#include "mdeclarativescreen_bridge.h"
#include "mdeclarativeinputcontext_bridge.h"
#include "gui/core/mpagestatus.h"
#include "gui/core/mdialogstatus.h"
#include "gui/core/mpageorientation.h"
#include "core/minversemousearea.h"
#include "core/mdeclarativeimageprovider.h"
#include "gui/core/mdeclarativeimplicitsizeitem.h"
#include "gui/components/mdeclarativemaskeditem.h"
#include "gui/components/mdatetimehelper.h"
#include "style/mthemeplugin.h"
#include "i18n/mtexttranslator.h"
#include "qmlmousefilter_bridge.h"
#include "gui/core/mscrolldecoratorsizer.h"
#include "i18n/mdeclarativeimattributeextension.h"
#include "i18n/mdeclarativeimobserver.h"
#include "gui/core/mtoolbarvisibility.h"
#include "core/qmlcommon.h"
#include "i18n/mlocalewrapper.h"
#include "gui/models/qrangemodel.h"
#include "core/qmluiextensionsnamespace.h"

class QmlUiExtensionsPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QmlUiExtensionsPlugin" FILE "QmlUiExtensionsPlugin.json")
#endif

public:
    void initializeEngine(QDeclarativeEngine *engine, const char *uri) {
        Q_ASSERT(uri == QLatin1String("QmlUiExtensions"));

        QDeclarativeExtensionPlugin::initializeEngine(engine, uri);

        // If plugin was initialized once, do not initialize it again
        if(!engine->imageProvider(QLatin1String("theme"))) {
            engine->addImageProvider(QLatin1String("theme"), new MDeclarativeImageProvider);

            engine->rootContext()->setContextProperty("screen", MDeclarativeScreen::instance());
            qmlRegisterUncreatableType<MDeclarativeScreen>(uri, 1,0, "Screen", "");

            engine->rootContext()->setContextProperty("platformWindow", QmlWindowState::instance());
            qmlRegisterUncreatableType<QmlWindowState>(uri, 1,0, "WindowState", "");

            engine->rootContext()->setContextProperty("theme", new MThemePlugin);
            qmlRegisterUncreatableType<MThemePlugin>(uri, 1,0, "Theme", "");

            engine->rootContext()->setContextProperty("inputContext", new MDeclarativeInputContext);
            qmlRegisterUncreatableType<MDeclarativeInputContext>(uri, 1,0, "InputContext", "");

            engine->rootContext()->setContextProperty("textTranslator", new MTextTranslator);
            qmlRegisterUncreatableType<MTextTranslator>(uri, 1,0, "TextTranslator", "");
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
            engine->rootContext()->setContextProperty("declarativeView", new MDeclarativeView());
            qmlRegisterUncreatableType<MDeclarativeView>(uri, 1,0, "DeclarativeView", "");
#endif
             engine->rootContext()->setContextProperty("dateTime", new MDateTimeHelper(engine->rootContext()));
             qmlRegisterUncreatableType<MDateTimeHelper>(uri, 1, 0, "DateTime", "");

            // Disable cursor blinking + make double tapping work the way it is done in lmt.
            QApplication *app = qobject_cast<QApplication*>(QApplication::instance());
            if (app) {
                app->setCursorFlashTime(0);
                app->setDoubleClickInterval(MEEGOTOUCH_DOUBLETAP_INTERVAL);
            }

            MLocaleWrapper *locale = new MLocaleWrapper;
            engine->rootContext()->setContextProperty("locale", locale);
            engine->rootContext()->setContextProperty("UiConstants", uiConstants(locale));
            qmlRegisterUncreatableType<MLocaleWrapper>(uri, 1,0, "Locale", "");
        }
    }

    void registerTypes(const char *uri) {
        Q_ASSERT(uri == QLatin1String("com.meego") || uri == QLatin1String("QmlUiExtensions") || uri == QLatin1String("Qt.labs.components.native"));
        qmlRegisterType<MDeclarativeStatusBar>(uri, 1,0, "StatusBarInternal");
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
        qmlRegisterType<MSnapshot>(uri, 1,0, "Snapshot");
#endif

        qmlRegisterUncreatableType<MPageStatus>(uri, 1,0, "PageStatus", "");
        qmlRegisterUncreatableType<MDialogStatus>(uri, 1,0, "DialogStatus", "");
        qmlRegisterUncreatableType<QmlWindowState>(uri, 1,0, "WindowState","");
        qmlRegisterUncreatableType<MPageOrientation>(uri, 1,0, "PageOrientation", "");
        qmlRegisterUncreatableType<MToolBarVisibility>(uri, 1,0, "ToolBarVisibility", "");
        qmlRegisterUncreatableType<MTextTranslator>(uri, 1,0, "TextTranslator", "");

        // Custom primitives
        qmlRegisterType<MDeclarativeImplicitSizeItem>(uri, 1,0, "ImplicitSizeItem");
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
        qmlRegisterType<MDeclarativeMaskedItem>(uri, 1,0, "MaskedItem");
#endif
        qmlRegisterType<MInverseMouseArea>(uri, 1,0, "InverseMouseArea");
        qmlRegisterType<QmlMouseFilter>(uri, 1,0, "MouseFilter");
        qmlRegisterType<QmlMouseEvent>(uri, 1,0, "MMouseEvent");
        qmlRegisterType<MDeclarativeIMAttributeExtension>(uri, 1,0, "SipAttributes");
        qmlRegisterType<MDeclarativeIMObserver>(uri, 1,0, "InputMethodObserver");

        qmlRegisterType<MScrollDecoratorSizer>(uri, 1,0, "ScrollDecoratorSizerCPP");
        qmlRegisterType<QmlGlobal>(uri, SINCE_VERSION(1, 1), "Global");
        qmlRegisterType<QRangeModel>(uri, SINCE_VERSION(1, 1), "RangeModel");

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
        // shader effect item (to be removed when fully supported in QML)
        qmlRegisterType<ShaderEffectItem>(uri, 1,0, "ShaderEffectItem");
        qmlRegisterType<ShaderEffectSource>(uri, 1,0, "ShaderEffectSource");
#endif

        qmlRegisterType<MInverseMouseArea>(uri, 1,0, "InverseMouseArea");

    }

    QDeclarativePropertyMap *uiConstants(MLocaleWrapper *locale = 0) {

        QString defaultFontFamily      = QLatin1String("Nokia Pure Text");
        QString defaultFontFamilyLight = QLatin1String("Nokia Pure Text Light");

#ifdef HAVE_MEEGOTOUCH
        // use arial when language is set to farsi
        if (locale && locale->language() == QLatin1String("fa")) {
            defaultFontFamily = QLatin1String("Arial");
            defaultFontFamilyLight = QLatin1String("Arial");
        }
#else
        Q_UNUSED(locale);
#endif // HAVE_MEEGOTOUCH

        QDeclarativePropertyMap *uiConstantsData = new QDeclarativePropertyMap();
        uiConstantsData->insert("DefaultMargin", QVariant(16));
        uiConstantsData->insert("ButtonSpacing", QVariant(6));
        uiConstantsData->insert("HeaderDefaultHeightPortrait", QVariant(72));
        uiConstantsData->insert("HeaderDefaultHeightLandscape", QVariant(46));
        uiConstantsData->insert("HeaderDefaultTopSpacingPortrait", QVariant(20));
        uiConstantsData->insert("HeaderDefaultBottomSpacingPortrait", QVariant(20));
        uiConstantsData->insert("HeaderDefaultTopSpacingLandscape", QVariant(16));
        uiConstantsData->insert("HeaderDefaultBottomSpacingLandscape", QVariant(14));
        uiConstantsData->insert("ListItemHeightSmall", QVariant(64));
        uiConstantsData->insert("ListItemHeightDefault", QVariant(80));

        uiConstantsData->insert("IndentDefault", QVariant(16)); // For left and right
        uiConstantsData->insert("GroupHeaderHeight", QVariant(40));

        QFont bodyTextFont;
        bodyTextFont.setFamily(defaultFontFamilyLight);
        bodyTextFont.setPixelSize(24);
        uiConstantsData->insert("BodyTextFont", QVariant(bodyTextFont));

        QFont headerFont;
        headerFont.setFamily(defaultFontFamilyLight);
        headerFont.setPixelSize(32);
        uiConstantsData->insert("HeaderFont", QVariant(headerFont));

        QFont groupHeaderFont;
        groupHeaderFont.setFamily(defaultFontFamily);
        groupHeaderFont.setPixelSize(18);
        groupHeaderFont.setBold(true);
        uiConstantsData->insert("GroupHeaderFont", QVariant(groupHeaderFont));

        QFont titleFont;
        titleFont.setFamily(defaultFontFamily);
        titleFont.setPixelSize(26);
        titleFont.setBold(true);
        uiConstantsData->insert("TitleFont", QVariant(titleFont));

        QFont smallTitleFont;
        smallTitleFont.setFamily(defaultFontFamily);
        smallTitleFont.setPixelSize(24);
        smallTitleFont.setBold(true);
        uiConstantsData->insert("SmallTitleFont", QVariant(smallTitleFont));

        QFont fieldLabelFont;
        fieldLabelFont.setFamily(defaultFontFamilyLight);
        fieldLabelFont.setPixelSize(22);
        uiConstantsData->insert("FieldLabelFont", QVariant(fieldLabelFont));
        uiConstantsData->insert("FieldLabelColor", QVariant(QColor("#505050")));

        QFont subTitleFont;
        subTitleFont.setFamily(defaultFontFamilyLight);
        subTitleFont.setPixelSize(22);
        uiConstantsData->insert("SubtitleFont", QVariant(subTitleFont));

        QFont itemInfoFont;
        itemInfoFont.setFamily(defaultFontFamilyLight);
        itemInfoFont.setPixelSize(18);
        uiConstantsData->insert("InfoFont", QVariant(itemInfoFont));

        return uiConstantsData;
    }
};

#include "plugin.moc"

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
Q_EXPORT_PLUGIN2(QmlUiExtensionsPlugin, QmlUiExtensionsPlugin);
#endif
