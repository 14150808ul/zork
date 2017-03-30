#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include <time.h>
#include <stdlib.h>

class Enemy : public Character
{
public:
    Enemy(QString name = "Enemy", int health = rand() % 10 + 1, int attack = 3);
    int getAttack() const;
private:
    const int luck;
};

#endif // ENEMY_H
