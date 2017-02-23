#ifndef ZORK_H
#define ZORK_H

#include <QWidget>
#include <QtWidgets>
#include <QSignalMapper>
#include "Room.h"
#include "item.h"


class ZorkUL : public QWidget
{
    Q_OBJECT

public:
    ZorkUL(QWidget *parent = 0);

    Room *currentRoom;

private slots:
    /*void goNorth();
    void goSouth();
    void goEast();
    void goWest();*/
    void displayMap();
    void go(QString direction);

private:
    void ZorkUL::createRooms();
    QPushButton *ZorkUL::createGoButton(const QString &text, const QString &direction, const char *member);
    QPushButton *ZorkUL::createButton(const QString &text, const char *member);
    QTextBrowser *output;

};


#endif
