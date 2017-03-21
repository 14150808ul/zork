#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character
{
public:
    Enemy(QString name = "Enemy", int health = 10, int attack = 3, int luck = 3);
    int getAttack() const;
private:
    int luck;
};

#endif // ENEMY_H
