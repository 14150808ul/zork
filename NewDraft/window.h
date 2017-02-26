#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>

//Test Crap
#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QApplication>
#include <QLabel>


// we have to work to make it tidy and not all over the place and nicer looking code, this is just an idea, about the buttons rooms


// very messy and ome hard coded values, not gonna be used for final project but ive ideas how to do things


class Room
{
public:
    Room(int room)
    {
        this->room = room;
        setDirections();
    }

    int getRoomNum() const
    {
        return room;
    }

    unsigned char validDirections() const
    {
        return directions;
    }

private:
    int room;
    unsigned char directions{0};

    void setDirections()
    {
        if (room > 6) directions |= 1;
        if (room < 4)	directions |= 2;
        if (room % 3 == 0) directions |= 4;
        if (28 % room == 0 && room != 2) directions |= 8;
    }
};



























// This is the display
class View : public QWidget
{
    Q_OBJECT
public:
    View( QWidget *parent = 0 ) : QWidget( parent ), grid(this), mapper(), label("Room 5",this)
    {
        setFixedSize(640,480);
        createButtons();
    }

    ~View()
    {
        for(int i = 0; i < 4;i++)
        {
            delete buttons[i];
            buttons[i] = nullptr;
        }
    }

    // shorter way of doing this using a for loop but involves casting, not worth it and two variables
public slots:
    void disableButtons(unsigned char direction)
    {
        if ((direction & 1) != 0) buttons[0]->setEnabled(false); else buttons[0]->setEnabled(true);
        if ((direction & 2) != 0) buttons[1]->setEnabled(false); else buttons[1]->setEnabled(true);
        if ((direction & 4) != 0) buttons[2]->setEnabled(false); else buttons[2]->setEnabled(true);
        if ((direction & 8) != 0) buttons[3]->setEnabled(false); else buttons[3]->setEnabled(true);
    }

    void displayRoom(int room)
    {
        QString text = "Room ";
        label.setText(text+QString::number(room));
    }

private:
    QPushButton *buttons[4];
    QGridLayout grid;
    QSignalMapper mapper;
    QLabel label;

    void createButtons()
    {
        grid.setAlignment(Qt::AlignTop | Qt::AlignLeft);
        grid.addWidget(&label, 0, 3);
        QString directions[4] = {"North","South","East","West"};
        for(int i = 0; i < 4; i++)
        {
            buttons[i] = new QPushButton(directions[i], this);
            if( i < 2 )grid.addWidget(buttons[i], 0, i);
            if( i > 1 )grid.addWidget(buttons[i], 1, i-2);
            connect(buttons[i], SIGNAL(pressed()), &mapper, SLOT(map()));
            mapper.setMapping(buttons[i], i+1);
        }
        connect(&mapper, SIGNAL(mapped(int)), this, SLOT(sendNumber(int)));
    }

    // Custom signal
signals:
    void sendSignal(int i);

private slots:
    void sendNumber(int i)
    {
        emit sendSignal(i);
    }
};



























// This is the brains hwo to change room and other crap
class Model: public QObject
{
   Q_OBJECT
public:
    Model()
    {
        // default is room 5 at the moment, can randomize it
        current = &rooms[4];
        qDebug() << current->getRoomNum();
    }

    ~Model()
    {
        delete current;
        current = nullptr;
    }

signals:
    void sendDirection(unsigned char);
    void sendRoom(int);

public slots:
    void setRoom(int direction)
    {
        switch (direction)
        {
            case 1: direction = +3;break;
            case 2: direction = -3;break;
            case 3: direction = +1;break;
            case 4: direction = -1;break;
        }
        current = &rooms[ (current->getRoomNum() - 1) + direction ];
        emit sendDirection( current->validDirections() );
        emit sendRoom(current->getRoomNum()); // these two should be wrapped into one
    }

private:
    Room rooms[9] = {(1),(2),(3),(4),(5),(6),(7),(8),(9)};
    Room * current;
};





























// This connects the two of them without any other two knowing about eachother except the controller
class Controller: public QObject
{
   Q_OBJECT
public:
   Controller( Model * m, View * v ): model(m), view(v)
   {
       // How they send signals to each other
       //custom  signal send  address of room maybe?
       connect(this->view, SIGNAL(sendSignal(int)), this->model ,SLOT(setRoom(int)));
       connect(this->model, SIGNAL(sendDirection(unsigned char)), this->view,SLOT(disableButtons(unsigned char)));
       connect(this->model, SIGNAL(sendRoom(int)), this->view,SLOT(displayRoom(int)));
   }

private:
    Model * model;
    View * view;
};


#endif // WINDOW_H
