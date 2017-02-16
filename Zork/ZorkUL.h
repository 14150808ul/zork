#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Player.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:


public:
	ZorkUL();
	string go(string direction);
    Parser parser;
    Room *currentRoom;
    Player *player;
    void createRooms();
    void createItems();
    void displayItems();
};

#endif /*ZORKUL_H_*/
