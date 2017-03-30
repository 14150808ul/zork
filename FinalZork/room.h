#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "item.h"
#include "enemy.h"
#include "player.h"

class Room
{
public:
    Room(int room_number);
    ~Room();
    int getRoomNumber() const;
    unsigned char getExits() const;
    void addRoomItem(Item* item);
    Item* removeItem(int index);
    const std::vector<Item*>& getRoomItems() const;
    void playerFight(Player* player);
    bool isEnemyDead() const;
private:
    int room_number;
    unsigned char exits;
    void setExits();
    std::vector<Item*> room_items;
    Character * enemy_ptr;
};

#endif // ROOM_H
