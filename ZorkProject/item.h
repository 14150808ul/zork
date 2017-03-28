#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
  friend QDebug &operator<<( QDebug &, Item & );

public:
    Item (QString description);
    QString getDescription() const;
private:
    QString description;
};

#endif // ITEM_H
