//==============================================
#include "MainWindow.h"
//==============================================
#include <QApplication>
#include <QOperatingSystemVersion>
#include <QTextCodec>
//==============================================
int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("windows-1251");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    //
    //initMsgTypesToHandleInMainWindow();
    // custom message handler for logging via qInfo qWarning qCritical
    //qInstallMessageHandler(messageHandler);

    // create qApp properties and set .pro defines into them
#ifdef APP_DISPLAY_NAME
    QApplication::setApplicationDisplayName(APP_DISPLAY_NAME);
#endif

#ifdef APP_PRODUCT
    QApplication::setApplicationName(APP_PRODUCT);
#endif

#ifdef APP_VERSION
    QApplication::setApplicationVersion(APP_VERSION);
#endif

#ifdef APP_COMPANY
    QApplication::setOrganizationName(APP_COMPANY);
#endif

#ifdef APP_COMPANY_URL
    QApplication::setOrganizationDomain(APP_COMPANY_URL);
#endif

#ifdef APP_COPYRIGHT
    qApp->setProperty("appCopyright", QString(APP_COPYRIGHT));
#endif

#ifdef APP_ICON
    qApp->setProperty("appIcon", QString(APP_ICON));
#endif

    //    ZTranslatorManager languageManager;
    //    languageManager.zp_installTranslatorsToApplication();

    // set dots on the splitter handle
    qApp->setStyleSheet("QSplitter::handle:vertical {height: 4px; image: "
                        "url(:/images/ZImages/vSplitterHandler.png);}"
                        "QSplitter::handle:horizontal {width: 4px; image: "
                        "url(:/images/ZImages/hSplitterHandler.png);}");

    // horizontal lines on table header views on win10
    QOperatingSystemVersion currentOS = QOperatingSystemVersion::current();
    if (currentOS >= QOperatingSystemVersion(QOperatingSystemVersion::Windows10))
    {
        qApp->setStyleSheet("QHeaderView::section{"
                            "border-top:0px solid #D8D8D8;"
                            "border-left:0px solid #D8D8D8;"
                            "border-right:1px solid #D8D8D8;"
                            "border-bottom: 1px solid #D8D8D8;"
                            "background-color:white;"
                            "padding:4px;"
                            "}"
                            "QTableCornerButton::section{"
                            "border-top:0px solid #D8D8D8;"
                            "border-left:0px solid #D8D8D8;"
                            "border-right:1px solid #D8D8D8;"
                            "border-bottom: 1px solid #D8D8D8;"
                            "background-color:white;"
                            "}");
    }

    // launch app

    // main window
    MainWindow w;

    // pointer to main window for message handler
    //    pMainWindow = &w;
    w.show();
    return a.exec();
}
//==============================================
