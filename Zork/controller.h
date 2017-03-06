#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDialog>
#include "view.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(Model *model, View *view);
    ~Controller();
    void setup();
private:
    Model *model;
    View *view;
private slots:
    void setRoom(int);
    void disable(unsigned char);
    void displayMap();
};

#endif // CONTROLLER_H
