#include <QtWidgets>
#include "ZorkUL.h"

using namespace std;

ZorkUL::ZorkUL(QWidget *parent)
    : QWidget(parent)
{
    createRooms();
    QPushButton *button_north = createButton("N", SLOT(goNorth()));
    button_north->setGeometry(QRect(QPoint(60, 0), QSize(41, 51)));
    QPushButton *button_south = createButton("S", SLOT(goSouth()));
    button_south->setGeometry(QRect(QPoint(60, 90), QSize(41, 51)));
    QPushButton *button_east = createButton("E", SLOT(goEast()));
    button_east->setGeometry(QRect(QPoint(100, 50), QSize(51, 41)));
    QPushButton *button_west = createButton("W", SLOT(goWest()));
    button_west->setGeometry(QRect(QPoint(10, 50), QSize(51, 41)));

    QPushButton *button_map = createButton("Map", SLOT(displayMap()));
    button_map->setGeometry(QRect(QPoint(80, 210), QSize(71, 41)));
    output = new QTextBrowser(this);
    output->setGeometry(QRect(QPoint(170, 20), QSize(391, 231)));

    setFont(*(new QFont("Papyrus", 20)));

}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;

    a = new Room("a");
        a->addItem(new Item("test", 2, 2));
    b = new Room("b");
    c = new Room("c");
        c->addItem(new Item("GroundHog", 4, 44));
        c->addItem(new Item("Daniel", 4, 44));
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(g, NULL, e, a);
    c->setExits(h, a, i, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(b, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, b, f);
    h->setExits(NULL, f, c, NULL);
    i->setExits(c, d, NULL, NULL);

    currentRoom = a;
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return currentRoom->longDescription();
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

void ZorkUL::goNorth(){
    output->setPlainText(QString::fromStdString( go("north")));
    qDebug() << "North";
}

void ZorkUL::goSouth(){
    output->setPlainText(QString::fromStdString( go("south")));
    qDebug() << "South";
}

void ZorkUL::goEast(){
     output->setPlainText(QString::fromStdString( go("east")));
    qDebug() << "East";
}

void ZorkUL::goWest(){
        output->setPlainText(QString::fromStdString( go("west")));
    qDebug() << "West";
}

void ZorkUL::displayMap(){
    QString mapString = QString::fromStdString( "[h] --- [f] --- [g]\n\n"
                                             "[c] --- [a] --- [b]\n\n"
                                             "[i] --- [d] --- [e]\n");
    output->setPlainText(mapString);
}

//Taken from Calculator Example
QPushButton *ZorkUL::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text, this);
            connect(button, SIGNAL(clicked()), this, member);
    return button;
}
