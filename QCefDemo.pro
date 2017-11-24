#-------------------------------------------------
#
# Project created by QtCreator 2017-11-24T15:22:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCefDemo
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += libqcef dtkwidget


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

RESOURCES += resources/resources.qrc
