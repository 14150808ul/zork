#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:
    Character(QString name, int health, int attack);
    virtual ~Character();
    QString getName() const;
    int getHealth() const;
    void setDamage(int damage);
   // void operator +(Character * character);
    virtual int getAttack() const = 0;
protected:
    int attack;
private:
    const QString name;
    int health;
};

#endif // CHARACTER_H
