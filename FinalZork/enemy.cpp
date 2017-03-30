#include "enemy.h"

#include <time.h>
#include<stdlib.h>

#include <QDebug>
#include <iostream>

Enemy::Enemy(QString name, int health, int attack) : Character(name, health, attack), luck(3) {

}

int Enemy::getAttack() const
{
    switch (rand() % luck)
    {
        case 0: return attack;
        case 1: return attack * 3;
        default: return 0;
    }
}
