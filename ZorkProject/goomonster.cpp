#include "goomonster.h"

GooMonster::GooMonster(QString name, int health, int attack) : Enemy(name, health, attack), magic(4)
{

}

int Enemy::getAttack() const
{
    switch (rand() % luck)
    {
        case 0: return attack;
        case 1: return attack * 2;
        default: return 0;
    }
}
