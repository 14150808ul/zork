#include "item.h"

Item::Item(QString inDescription) {
    description = inDescription;
}

Item::Item() {

}

QString Item::getDescription()
{
    return description;
}
