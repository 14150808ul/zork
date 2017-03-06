#include "model.h"

Model::Model() : rooms{(1),(2),(3),(4),(5),(6),(7),(8),(9)}
{
    current_room_ptr = &rooms[4];
}

Model::~Model()
{
    current_room_ptr = nullptr;
}

void Model::setRoomPosition(int num)
{
    current_room_ptr = &rooms[(current_room_ptr->getRoomNumber() - 1) + num];
    emit sendExits(current_room_ptr->getExits());
}

int Model::getCurrentRoom() const
{
    return current_room_ptr->getRoomNumber();
}
