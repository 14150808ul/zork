#include "controller.h"
#include "logger.h"

#include <QDebug>
#include <iostream>

Controller::Controller(Model *model, View *view) : model(model), view(view)
{
    connect(model, SIGNAL(updateRoom()), this, SLOT(updateView()));
    connect(view, SIGNAL(updateRoom(int)), this, SLOT(updateRoom(int)));
    connect(view, SIGNAL(updateCurrentRoomItems(int)), this, SLOT(updateRoomItems(int)));
    connect(view, SIGNAL(updateCurrentPlayerItems(int)), this, SLOT(updatePlayerItems(int)));
    connect(view, SIGNAL(attackEnemy()), this, SLOT(attackEnemy()));
    model->setCurrentRoom();
}

Controller::~Controller()
{
    model = nullptr;
    view = nullptr;
}

void Controller::updateRoom(int num)
{
    model->setCurrentRoom(num);
}

void Controller::updateView() //update many things on the view
{
    view->updateRoomButtons(model->getCurrentRoom()->getExits(), model->getCurrentRoom()->getRoomNumber());
    view->populateList(model->getCurrentRoom()->getRoomItems(), model->getPlayer()->getPlayerItems());
    view->disableAttack(model->getCurrentRoom()->isEnemyDead());
}


void Controller::updatePlayerItems(int num)
{
    *model->getPlayer() + model->getCurrentRoom()->removeItem(num); //operator overload to add item to current player from room
    updateView();
}

void Controller::updateRoomItems(int num)
{
    model->getCurrentRoom()->addRoomItem(*model->getPlayer() - num); //operator overload player and a number to return an item
    updateView();
}

void Controller::attackEnemy()
{
    model->getCurrentRoom()->playerFight(model->getPlayer());
    updateView(); //update the view
    Logger::log(*(model->getPlayer()), QString("Player attacks..."));
}
