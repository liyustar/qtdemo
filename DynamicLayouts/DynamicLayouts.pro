#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:22:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DynamicLayouts
TEMPLATE = app

CONFIG += debug_and_release

CONFIG(debug, debug|release) {
    TARGET = debug_DynamicLayouts
} else {
    TARGET = release_DynamicLayouts
}

SOURCES += src/main.cpp\
        src/dynamiclayouts.cpp

HEADERS  += include/dynamiclayouts.h

UI_DIR   =  ui

INCLUDEPATH += include ui

DESTDIR = bin
MOC_DIR = tmp
# OBJECTS_DIR = tmp
