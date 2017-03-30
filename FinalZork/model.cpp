#include "model.h"

#include <time.h>
#include <stdlib.h>

Model::Model() : player(new Player)
{
    srand(time(NULL));
    for(int i = 0; i < 9; i++)
        rooms[i] = new Room(i+1);

    for(int i = 0; i < 4;i++)
        rooms[rand() % 9]->addRoomItem(new Item("key"));

   current_room_ptr = rooms[4];
}

Model::~Model()
{
    delete player;
    player = nullptr;
    current_room_ptr = nullptr;
    
    for(int i = 0; i < 9; i++)
    {
        delete rooms[i];
        rooms[i] = nullptr;
    }
}

Room* Model::getCurrentRoom() const
{
    return current_room_ptr;
}

void Model::setCurrentRoom(int num)
{
    current_room_ptr = rooms[(current_room_ptr->getRoomNumber() - 1) + num];
    emit updateRoom();
}

Player* Model::getPlayer() const
{
    return player;
}
