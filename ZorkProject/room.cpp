#include "room.h"

Room::Room(int room_number) : room_number(room_number), exits(0), enemy_ptr(new Enemy("Room " + QString::number(room_number) + " enemy"))
{
    setExits();
}

Room::~Room()
{

}

int Room::getRoomNumber() const
{
    return room_number;
}

unsigned char Room::getExits() const
{
    return exits;
}

void Room::setExits()
{
    if (room_number > 6) exits |= 1;
    if (room_number < 4) exits |= 2;
    if (room_number % 3 == 0) exits |= 4;
    if (28 % room_number == 0 && room_number != 2) exits |= 8;
}

void Room::addRoomItem(Item* item)
{
    room_items.push_back(item);
}

Item* Room::removeItem(int index)
{
    Item* temp = room_items[index];
    room_items.erase(room_items.begin() + index);
    return temp;
}

const std::vector<Item*>& Room::getRoomItems() const
{
    return room_items;
}

void Room::playerFight(Player *player)
{
    player->setDamage(enemy_ptr->getAttack());
    enemy_ptr->setDamage(player->getAttack());

    if(enemy_ptr->getHealth() <= 0)
    {
        delete enemy_ptr;
        enemy_ptr = nullptr;
    }
}

bool Room::isEnemyDead() const
{
    return (enemy_ptr != nullptr) ? true : false;
}
