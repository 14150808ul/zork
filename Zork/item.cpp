#include "item.h"

Item::Item(QString inDescription) {
    description = inDescription;
}

QString Item::getDescription()
{
    return description;
}
