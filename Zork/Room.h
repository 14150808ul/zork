#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <QString>
#include <QMovie>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    QString description;
    map<QString, Room*> exits;
    QMovie *bot;
    QPixmap *background;
    vector <Item*> itemsInRoom;

public:
    Room(QString description, QPixmap *background);
    ~Room();

    void setExits(Room *north, Room *east, Room *south, Room *west);
    Room* nextRoom(QString direction);

    QString getDescription();

    void addItem(Item *inItem);
    void removeItem(int index);

    vector<Item*> getItemsInRoom();

    QMovie* getBot();
    void setBot(QMovie *bot);

    QPixmap* getBackground();
    void setBackground(QPixmap *image);
};

#endif
