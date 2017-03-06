#include "room.h"

Room::Room(int room) : room(room), exits(0)
{
    setExits();
}

int Room::getRoomNumber() const
{
    return room;
}

unsigned char Room::getExits() const
{
    return exits;
}

void Room::setExits()
{
    if (room > 6) exits |= 1;
    if (room < 4) exits |= 2;
    if (room % 3 == 0) exits |= 4;
    if (28 % room == 0 && room != 2) exits |= 8;
}
