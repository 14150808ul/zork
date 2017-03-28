#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "item.h"
#include <vector>

#ifdef _WIN32
    #define NAME "Bill"
#elif __APPLE__
    #define NAME "Steve"
#else
    #define NAME "Linus"
#endif

class Player : public Character
{
public:
    Player(QString name = NAME, int health=100, int attack = 5);
    int getAttack() const;
    void operator+(Item* item);
    Item* operator-(int index);
    const std::vector<Item*>& getPlayerItems() const;
private:
    std::vector<Item*> player_items;
    int key_counter;
};

#endif // PLAYER_H
