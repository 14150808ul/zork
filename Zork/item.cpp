#include "item.h"

Item::Item(QString item_name, int weight) : item_name(item_name)
{
    this->weight = weight;
}

QString Item::getItemName() const
{
    return item_name;
}

int Item::getWeight() const
{
    return weight;
}

QString Item::getDescription() const
{
    return item_name + " weighs " + weight;
}
