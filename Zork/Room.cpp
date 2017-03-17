#include "Room.h"

Room::Room(QString description, QPixmap *background) {
    this->description = description;
  this->background = background;
    this->bot = NULL;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

Room* Room::nextRoom(QString direction) {
    map<QString, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<QString, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(inItem);
}

void Room::removeItem(int index){
    itemsInRoom.erase(itemsInRoom.begin() + index);
}

QString Room::getDescription(){
    return description;
}


QMovie* Room::getBot(){
    return bot;
}

void Room::setBot(QMovie *bot){
    this->bot = bot;
}

vector<Item *> Room::getItemsInRoom(){
    return itemsInRoom;
}

QPixmap* Room::getBackground(){
  return background;
};
