#include "player.h"

Player::Player(QString name, int health, int attack): Character(name, health, attack)
{

}

int Player::getAttack() const
{
    return attack;
}
