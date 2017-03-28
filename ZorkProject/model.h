#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "room.h"
#include "player.h"
#include "enemy.h"

class Model : public QObject
{
    Q_OBJECT
public:
    Model();
    ~Model();
    void setCurrentRoom(int num = 0);
    Player* getPlayer() const;
    Room* getCurrentRoom() const;
private:
    Player* player;
    Character *enemy_character;
    Room* rooms[9];
    Room* current_room_ptr;
signals:
    void updateRoom();
};

#endif // MODEL_H
