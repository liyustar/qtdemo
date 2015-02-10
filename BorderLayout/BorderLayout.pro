#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:22:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BorderLayout
TEMPLATE = app

CONFIG += debug_and_release

CONFIG(debug, debug|release) {
    TARGET = debug_BorderLayout
} else {
    TARGET = release_BorderLayout
}

SOURCES += src/main.cpp\
        src/window.cpp\
        src/borderlayout.cpp

HEADERS  += include/borderlayout.h\
        include/window.h

UI_DIR   =  ui

INCLUDEPATH += include ui

DESTDIR = bin
MOC_DIR = tmp
# OBJECTS_DIR = tmp
