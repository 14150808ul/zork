#include "Player.h"

Player::Player(){

}

void Player::addItem(Item *inItem) {
    playerItems.push_back(*inItem);
}

int Player::numberOfItems() {
    return playerItems.size();
}

int Player::isInPlayerItems(string inString)
{
    int sizeItems = (playerItems.size());
    if (playerItems.size() < 1) {
        return false;
        }
    else if (playerItems.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( playerItems[x].getShortDescription());
            if (tempFlag == 0) {
                playerItems.erase(playerItems.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}

