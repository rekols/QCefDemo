#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QVBoxLayout>
#include <qcef_context.h>
#include <qcef_web_page.h>
#include <qcef_web_settings.h>
#include <qcef_web_view.h>

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget *m_mainWidget;
    QVBoxLayout *m_mainLayout;
    QCefWebView *m_webView;
};

#endif // MAINWINDOW_H
