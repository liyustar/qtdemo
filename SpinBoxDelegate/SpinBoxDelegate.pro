#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T15:37:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpinBoxDelegate
TEMPLATE = app

CONFIG += debug_and_release

CONFIG(debug, debug|release) {
    TARGET = debug_SpinBoxDelegate
} else {
    TARGET = release_SpinBoxDelegate
}

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/delegate.cpp

HEADERS  += include/mainwindow.h\
            include/delegate.h

UI_DIR   =  ui

INCLUDEPATH += include ui

DESTDIR = bin
MOC_DIR = tmp
# OBJECTS_DIR = tmp
