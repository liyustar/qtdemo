#-------------------------------------------------
#
# Project created by QtCreator 2015-02-08T20:51:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad
TEMPLATE = app


SOURCES += src/main.cpp\
        src/notepad.cpp

HEADERS  += include/notepad.h

FORMS    += ui/notepad.ui
UI_DIR   =  ui

INCLUDEPATH += include ui

DESTDIR = bin
MOC_DIR = tmp
OBJECTS_DIR = tmp
