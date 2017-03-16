#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <QString>
#include <iostream>
using namespace std;

class Item {
private:
    QString description;

public:
    Item (QString description);
    QString getDescription();
};

#endif /*ITEM_H_*/
