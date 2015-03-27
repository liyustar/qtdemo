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
        src/constant.cpp\
        src/type.cpp\
        src/mainwindow.cpp\
        src/methodinvoker.cpp\
        src/orderwidget.cpp\
        src/singleorderform.cpp\
        src/singleordertab.cpp\
        src/singleordertablemodel.cpp\
        src/singleorderformdialog.cpp

HEADERS  += include/mainwindow.h\
            include/constant.h\
            include/type.h\
            include/methodinvoker.h\
            include/orderwidget.h\
            include/singleorderform.h\
            include/singleordertab.h\
            include/singleordertablemodel.h\
            include/singleorderformdialog.h

# RESOURCES += rc/tradebookdemo.qrc

UI_DIR   =  ui

INCLUDEPATH += include ui /home/lyx/Tool/curl-7.41.0/include

DESTDIR = bin
MOC_DIR = tmp
# OBJECTS_DIR = tmp

unix:LIBS += -lcurl
