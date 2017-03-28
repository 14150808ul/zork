#include "item.h"

Item::Item(QString description) : description(description)
{

}

QString Item::getDescription() const
{
    return description;
}
