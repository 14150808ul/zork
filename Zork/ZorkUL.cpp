#include <iostream>

using namespace std;
#include "ZorkUL.h"
/*
int main(int argc, char argv[]) {
	ZorkUL temp;
	temp.play();
	return 0;
}
*/
ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;

	a = new Room("a");
	b = new Room("b");
	c = new Room("c");
        c->addItem(new Item("GroundHog", 4, 44));
        c->addItem(new Item("Daniel", 4, 44));
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
    i = new Room("i");

//             (N, E, S, W)
	a->setExits(f, b, d, c);
    b->setExits(g, NULL, e, a);
    c->setExits(h, a, i, NULL);
	d->setExits(a, e, NULL, i);
    e->setExits(b, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, b, f);
    h->setExits(NULL, f, c, NULL);
    i->setExits(c, d, NULL, NULL);

        currentRoom = a;
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
