#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <QString>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    QString description;
    map<QString, Room*> exits;
    QString exitString();

public:
    int numberOfItems();
    Room(QString description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    QString shortDescription();
    QString longDescription();
    Room* nextRoom(QString direction);
    void addItem(Item *inItem);
    QString displayItem();
    int isItemInRoom(QString inString);
    void removeItemFromRoom(int location);
    vector <Item> itemsInRoom;
};

#endif
