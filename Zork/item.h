#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    Item(QString item_name, int weight = 1);
    QString getItemName() const;
    QString getDescription() const;
    int getWeight() const;
private:
    QString item_name;
    int weight;
};

#endif // ITEM_H
