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
    ~ZorkUL();



private slots:
    void go(QString direction);
    void dropItem();
    void takeItem();

private:
    void createRooms();
    void createGUI();

    void populateLists();
    void updateRoom();

    QPushButton *createGoButton(const QString &text, const QString &direction);
    QPushButton *createButton(const QString &text, const char *member);

    int player_key_count; //number of keys the player has picked up
    Room *currentRoom;  //player's current room
    QLabel *output;   //The main display panel - contains room's background image
    QLabel *bot_label;  //Contains bot image
    QListWidget *player_items_list;   //List widget for player's inventory
    QListWidget *room_items_list;   //List widget for items in room

    vector <Item*> player_items; //Will be moved to Player class

};


#endif
