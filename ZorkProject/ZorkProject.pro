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
    zork.cpp \
    character.cpp \
    player.cpp \
    enemy.cpp \
    item.cpp \
    logger.cpp

HEADERS  += \
    view.h \
    controller.h \
    model.h \
    room.h \
    zork.h \
    character.h \
    player.h \
    enemy.h \
    item.h \
    logger.h

RESOURCES += \
    rsc.qrc
