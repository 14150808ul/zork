#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <QString>
#include <iostream>
using namespace std;

class Item {
  friend QDebug &operator<<( QDebug &, Item & );

protected:
    QString description;

public:
    Item (QString description);
    ~Item ();
    QString getDescription();
};
#endif /*ITEM_H_*/
