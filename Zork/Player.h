#ifndef PLAYER_H_
#define PLAYER_H__

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Player {

private:
public:
    int numberOfItems();
    Player();
    void addItem(Item *inItem);
    int isInPlayerItems(string inString);
    void removeFromPlayerItems(int location);
    vector <Item> playerItems;
};

#endif
