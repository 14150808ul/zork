#include <QtWidgets>
#include "ZorkUL.h"

using namespace std;

ZorkUL::ZorkUL(QWidget *parent)
    : QWidget(parent)
{
    createRooms();
    QPushButton *button_north = createGoButton("N", "north", SLOT(goNorth()));
    button_north->setGeometry(QRect(QPoint(60, 0), QSize(41, 51)));
    QPushButton *button_south = createGoButton("S", "south", SLOT(goSouth()));
    button_south->setGeometry(QRect(QPoint(60, 90), QSize(41, 51)));
    QPushButton *button_east = createGoButton("E", "east", SLOT(goEast()));
    button_east->setGeometry(QRect(QPoint(100, 50), QSize(51, 41)));
    QPushButton *button_west = createGoButton("W","west", SLOT(goWest()));
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

void ZorkUL::go(QString direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
       output->setPlainText( currentRoom->longDescription());
    else
    {
        currentRoom = nextRoom;
        output->setPlainText( currentRoom->longDescription());
    }

}

void ZorkUL::displayMap(){
    QString mapString = QString::fromStdString( "[h] --- [f] --- [g]\n\n"
                                             "[c] --- [a] --- [b]\n\n"
                                             "[i] --- [d] --- [e]\n");
    output->setPlainText(mapString);
}

//Taken from Calculator Example
QPushButton *ZorkUL::createGoButton(const QString &text, const QString &direction,  const char *member)
{
    QSignalMapper *mapper = new QSignalMapper();
    QPushButton *button = new QPushButton(text, this);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
            mapper->setMapping(button, direction);
            connect( mapper, SIGNAL(mapped(QString)), this, SLOT( go(QString)));


    return button;
}

QPushButton *ZorkUL::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text, this);
            connect(button, SIGNAL(clicked()), this, member);
    return button;
}
