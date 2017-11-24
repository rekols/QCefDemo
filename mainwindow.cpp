#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_mainLayout = new QVBoxLayout(this);
    m_webView = new QCefWebView();
    m_webView->setUrl(QUrl("qrc://resources/index.html"));

    m_mainLayout->setMargin(0);
    m_mainLayout->addWidget(m_webView);
}

MainWindow::~MainWindow()
{

}
