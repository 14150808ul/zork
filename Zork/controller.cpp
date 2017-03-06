#include "controller.h"

Controller::Controller(Model *model, View *view) : model(model), view(view)
{

}

Controller::~Controller()
{
    model = nullptr;
    view = nullptr;
}

void Controller::setup()
{
    connect(view, SIGNAL(changeRooms(int)), this, SLOT(setRoom(int)));
    connect(model, SIGNAL(sendExits(unsigned char)), this, SLOT(disable(unsigned char)));
    connect(view, SIGNAL(showMap()), this, SLOT(displayMap()));
}

void Controller::setRoom(int num)
{
    model->setRoomPosition(num);
}

void Controller::disable(unsigned char exits)
{
    view->disableButtons(exits);
}

void Controller::displayMap()
{
    view->showOnMap(model->getCurrentRoom());
}
