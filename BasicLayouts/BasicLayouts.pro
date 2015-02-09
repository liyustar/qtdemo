#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T19:06:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BasicLayouts
TEMPLATE = app


SOURCES += src/main.cpp\
        src/basiclayouts.cpp

HEADERS  += include/basiclayouts.h

FORMS    += ui/basiclayouts.ui
UI_DIR   =  ui

INCLUDEPATH += include ui

DESTDIR = bin
MOC_DIR = tmp
OBJECTS_DIR = tmp
