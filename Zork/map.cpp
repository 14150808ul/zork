#include "map.h"

Map::Map(QWidget *parent) : QDialog(parent), position_on_map(new QLabel(this))
{
    setFixedSize(300,300);
    position_on_map->setGeometry(90,40, 200, 200);
}

void Map::showOnMap(int room)
{
    position_on_map->setText("You are in room  "+((QString)(room + 64))+"\n\nG\tH\tI\n\nD\tE\tF\n\nA\tB\tC");
}
