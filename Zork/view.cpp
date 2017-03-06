#include "view.h"

View::View(QWidget* parent) : QWidget(parent), map(), pos("Map",this), my_map(this)
{
    setFixedSize(800, 600);
    createButtons();
	setButtonPos();
    connect(&pos, SIGNAL(pressed()), this, SIGNAL(showMap()));
}

View::~View()
{
    for (int i = 0; i < length; ++i)
    {
        delete buttons[i];
        buttons[i] = nullptr;
    }
}

void View::showOnMap(int num)
{
    my_map.showOnMap(num);
    my_map.setModal(true);
    my_map.show();
}

void View::disableButtons(unsigned char exits)
{
    for (unsigned char i = 0, j = 1; i < length; ++i, j<<=1)
        buttons[i]->setEnabled((exits & j) == 0 ? true : false);
}

void View::createButtons()
{
    QString directions[4] = {"North","South","East","West"};
    int numbered_position[4] = {+3,-3,+1,-1};

    for (int i = 0; i < length; ++i)
    {
        buttons[i] = new QPushButton(directions[i], this);
        connect(buttons[i],SIGNAL(pressed()), &map, SLOT(map()));
        map.setMapping(buttons[i],numbered_position[i]);
    }
    connect(&map, SIGNAL(mapped(int)), this, SIGNAL(changeRooms(int)));
}

void View::setButtonPos()
{
	buttons[0]->setGeometry(60, 0, 41, 51);
    buttons[1]->setGeometry(60, 90, 41, 51);
    buttons[2]->setGeometry(100, 50, 51, 41);
    buttons[3]->setGeometry(10, 50, 51, 41);
    pos.setGeometry(80,210,71,41);
}
