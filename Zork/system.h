#ifndef SYSTEM_H
#define SYSTEM_H

#include <QApplication>
#include "view.h"
#include "model.h"
#include "controller.h"

class System : public QApplication
{
public:
    System(int argc, char *argv[]);
    void display();
private:
    Model model;
    View view;
    Controller controller;
};

#endif // SYSTEM_H
