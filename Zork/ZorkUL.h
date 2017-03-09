#ifndef ZORK_H
#define ZORK_H

#include <QWidget>
#include <QtWidgets>
#include <QSignalMapper>
#include "Room.h"
#include "item.h"
#include "Player.h"


class ZorkUL : public QWidget
{
    Q_OBJECT

public:
    ZorkUL(QWidget *parent = 0);

    Room *currentRoom;

private slots:
    void displayMap();
    void go(QString direction);
    void dropItem();
    void takeItem();

private:
    void createRooms();
    void createGUI();
    void populateLists();
    QPushButton *createGoButton(const QString &text, const QString &direction);
    QPushButton *createButton(const QString &text, const char *member);
    QLabel *output;
    QListWidget *player_items_list;
    QListWidget *room_items_list;

    vector <Item> player_items; //Will be moved to Player class

};


#endif
