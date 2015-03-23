#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T15:37:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AddressBook
TEMPLATE = app

CONFIG += debug_and_release

CONFIG(debug, debug|release) {
    TARGET = debug_AddressBook
} else {
    TARGET = release_AddressBook
}

SOURCES += src/main.cpp\
        src/mainwindow.cpp

HEADERS  += include/mainwindow.h

# RESOURCES += rc/addressbook.qrc

UI_DIR   =  ui

INCLUDEPATH += include ui

DESTDIR = bin
MOC_DIR = tmp
# OBJECTS_DIR = tmp
