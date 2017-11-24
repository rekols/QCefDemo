#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    m_mainWidget = new QWidget;
    m_mainLayout = new QVBoxLayout(m_mainWidget);
    m_webView = new QCefWebView();
    m_webView->setUrl(QUrl("qrc://resources/index.html"));

    m_mainLayout->setMargin(0);
    m_mainLayout->addWidget(m_webView);

    setCentralWidget(m_mainWidget);
}

MainWindow::~MainWindow()
{

}
