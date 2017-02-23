#-------------------------------------------------
#
# Project created by QtCreator 2017-02-06T19:52:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zork
TEMPLATE = app


SOURCES += main.cpp\
    item.cpp \
    Room.cpp \
    ZorkUL.cpp \
    Player.cpp

HEADERS  += \
    item.h \
    Room.h \
    ZorkUL.h \
    Player.h

FORMS    += mainwindow.ui

DISTFILES += \
    Zork.pro.user