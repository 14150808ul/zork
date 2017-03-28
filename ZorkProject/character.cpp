#include "character.h"

Character::Character(QString name, int health, int attack) : attack(attack), name(name), health(health)
{

}

Character::~Character()
{

}

int Character::getHealth() const
{
    return health;
}

QString Character::getName() const
{
    return name;
}

void Character::setDamage(int damage)
{
    health -= damage;
}
