#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T15:37:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TradeBookDemo
TEMPLATE = app

CONFIG += debug_and_release

CONFIG(debug, debug|release) {
    TARGET = debug_TradeBookDemo
} else {
    TARGET = release_TradeBookDemo
}

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/orderwidget.cpp\
        src/singleordertab.cpp\
        src/singleordertablemodel.cpp

HEADERS  += include/mainwindow.h\
            include/orderwidget.h\
            include/singleordertab.h\
            include/singleordertablemodel.h

# RESOURCES += rc/tradebookdemo.qrc

UI_DIR   =  ui

INCLUDEPATH += include ui

DESTDIR = bin
MOC_DIR = tmp
# OBJECTS_DIR = tmp
