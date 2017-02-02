QT += core
QT -= gui

CONFIG += c++11

TARGET = Zork_console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    item.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp

DISTFILES += \
    Zork_console.pro.user

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    item.h \
    Parser.h \
    Room.h \
    ZorkUL.h
