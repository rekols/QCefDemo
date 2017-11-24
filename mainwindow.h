#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <qcef_context.h>
#include <qcef_web_page.h>
#include <qcef_web_settings.h>
#include <qcef_web_view.h>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QVBoxLayout *m_mainLayout;
    QCefWebView *m_webView;
};

#endif // MAINWINDOW_H
