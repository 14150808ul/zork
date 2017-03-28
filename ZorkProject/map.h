#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QLabel>

class Map : public QDialog
{
    Q_OBJECT
public:
    Map(QWidget *parent = 0);
    void showOnMap(int room);
private:
    QLabel *position_on_map;
};

#endif // MAP_H
