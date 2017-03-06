#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QSignalMapper>
#include "map.h"

class View : public QWidget
{
    Q_OBJECT
public:
    View(QWidget* parent = 0);
    ~View();
    void disableButtons(unsigned char exits);
    void showOnMap(int num);
private:
    QSignalMapper map;
    QPushButton pos;
    Map my_map;
    QPushButton* buttons[4];
    int length = sizeof(buttons) / sizeof(buttons[0]);
    void createButtons();
    void setButtonPos();
signals:
    void changeRooms(int);
    void showMap();
};

#endif // MAINWINDOW_H
