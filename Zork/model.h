#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "room.h"

class Model : public QObject
{
    Q_OBJECT
public:
    Model();
    ~Model();
    void setRoomPosition(int num);
    int getCurrentRoom() const;
private:
    Room rooms[9];
    Room* current_room_ptr;
signals:
    void sendExits(unsigned char);
};

#endif // MODEL_H
