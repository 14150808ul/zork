#include "Player.h"

Player::Player(){

}

void Player::addItem(Item *inItem) {
    playerItems.push_back(*inItem);
}

int Player::numberOfItems() {
    return (int)playerItems.size();
}

int Player::isInPlayerItems(QString inQString)
{
    int sizeItems = (int)playerItems.size();
    if (playerItems.size() < 1) {
        return false;
    }
    else if (playerItems.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inQString with short description
            int tempFlag = inQString.compare( playerItems[x].getDescription());
            if (tempFlag == 0) {
                playerItems.erase(playerItems.begin()+x);
                return x;
            }
            x++;
        }
    }
    return -1;
}

