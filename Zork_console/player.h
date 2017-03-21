#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "item.h"
#include <vector>

class Player : public Character
{
public:
    Player(QString name = "Character", int health=100, int attack = 10);
    int getAttack() const;
    void setItem(Item*);
    Item* getItem() const;
private:
    std::vector <Item*> playerItems;
};

#endif // PLAYER_H
