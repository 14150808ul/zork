QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZorkProject
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    view.cpp \
    controller.cpp \
    model.cpp \
    room.cpp \
    system.cpp \
    item.cpp \
    map.cpp

HEADERS  += \
    view.h \
    controller.h \
    model.h \
    room.h \
    system.h \
    item.h \
    map.h
