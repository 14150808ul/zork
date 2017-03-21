#include "enemy.h"

#include <time.h>
#include<stdlib.h>

Enemy::Enemy(QString name, int health, int attack, int luck) : Character(name, health, attack), luck(luck)
{

}

int Enemy::getAttack() const
{
    switch (rand() % luck + 1)
    {
        case 1: return attack;
        case 2: return attack * 2;
        default: return 0;
    }
}
