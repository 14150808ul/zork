#ifndef ZORK_H
#define ZORK_H

#include <QWidget>
#include <QtWidgets>

#include "Room.h"
#include "item.h"


class ZorkUL : public QWidget
{
    Q_OBJECT

public:
    ZorkUL(QWidget *parent = 0);
    string ZorkUL::go(string direction);
    Room *currentRoom;

private slots:
    void goNorth();
    void goSouth();
    void goEast();
    void goWest();
    void displayMap();

private:
    void ZorkUL::createRooms();
    QPushButton *ZorkUL::createButton(const QString &text, const char *member);
    QTextBrowser *output;

};


#endif
