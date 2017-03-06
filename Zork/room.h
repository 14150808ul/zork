#ifndef ROOM_H
#define ROOM_H

class Room
{
public:
    Room(int room);
    int getRoomNumber() const;
    unsigned char getExits() const;
private:
    int room;
    unsigned char exits;
    void setExits();
};

#endif // ROOM_H
