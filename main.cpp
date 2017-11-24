#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <qcef_context.h>
#include <qcef_util.h>

const char kPlatformThemeName[] = "QT_QPA_PLATFORMTHEME";
const char kGtk2Theme[] = "gtk2";

int main(int argc, char *argv[])
{
    // If platform theme name is empty, fallback to gtk2.
    // gtk2 theme is included in libqt5libqgtk2 package.
    if (qgetenv(kPlatformThemeName) != kGtk2Theme) {
      qputenv(kPlatformThemeName, kGtk2Theme);
    }

    QCefGlobalSettings settings;
    // Do not use sandbox.
    settings.setNoSandbox(true);

    // Flash plugin only works on x86 platform.
    if (IsX86Architecture()) {
      // Pepper flash plugin crashes on chromium 60
  //    settings.setPepperFlash(true);
    }

    // Use socks5 proxy.
  //  settings.setProxyServer("socks5://127.0.0.1:1080");

    // Open http://localhost:9222 in chromium browser to see dev tools.
    settings.setRemoteDebug(true);
    settings.setLogSeverity(QCefGlobalSettings::LogSeverity::Info);

    // Register user script.
    settings.registerUserScript(":/resources/user_script.js",
                                QUrl("qrc://resources/user_script.js"));

    // Disable GPU process.
    settings.addCommandLineSwitch("--disable-gpu", "");

    // Enable aggressive storage commit to minimize data loss.
    // See public/common/content_switches.cc.
    settings.addCommandLineSwitch("--enable-aggressive-domstorage-flushing", "");

    const int exit_code = QCefInit(argc, argv, settings);
    if (exit_code >= 0) {
      return exit_code;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600, 400);
    w.show();

    QCefBindApp(&a);

    return a.exec();
}
