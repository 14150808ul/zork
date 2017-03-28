#include "player.h"
#include <QDebug>

Player::Player(QString name, int health, int attack): Character(name, health, attack), key_counter(0)
{

}

int Player::getAttack() const
{
    return attack;
}

void Player::operator+(Item* item)
{
    player_items.push_back(item);

    if(item->getDescription().contains("key"))
        key_counter++;
}

Item* Player::operator-(int index)
{
    Item* temp = player_items[index];
    player_items.erase(player_items.begin() + index);

    if(temp->getDescription().contains("key"))
        key_counter--;

    return temp;
}

const std::vector<Item*>& Player::getPlayerItems() const
{
    return player_items;
}

QDebug &operator<<( QDebug &out, Player &P ){
  out << "Name -- " << P.getName() << "\nHealth -- " << P.getHealth();
  return out;
}
