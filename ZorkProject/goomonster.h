#ifndef GOOMONSTER_H
#define GOOMONSTER_H

#include <enemy.h>

class GooMonster : public Enemy
{
public:
    GooMonster(String name="Goo Monster", int health = 12, int attack=4);
    int getAttack() const;
private:
    int magic;
};

#endif // GOOMONSTER_H
