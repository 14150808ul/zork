#ifndef SYSTEM_H
#define SYSTEM_H

#include <QApplication>
#include "view.h"
#include "model.h"
#include "controller.h"

class Zork : public QApplication
{
public:
     explicit Zork(int argc, char *argv[]);
private:
    Model model;
    View view;
    Controller controller;
};

#endif // SYSTEM_H
