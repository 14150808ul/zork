#include <QtWidgets>
#include "ZorkUL.h"
using namespace std;

ZorkUL::ZorkUL(QWidget *parent)
    : QWidget(parent)
{
    createRooms();
    QPushButton *button_north = createGoButton("N", "north");
    button_north->setGeometry(QRect(QPoint(60, 0), QSize(41, 51)));
    QPushButton *button_south = createGoButton("S", "south");
    button_south->setGeometry(QRect(QPoint(60, 90), QSize(41, 51)));
    QPushButton *button_east = createGoButton("E", "east");
    button_east->setGeometry(QRect(QPoint(100, 50), QSize(51, 41)));
    QPushButton *button_west = createGoButton("W","west");
    button_west->setGeometry(QRect(QPoint(10, 50), QSize(51, 41)));

    QPushButton *button_map = createButton("Map", SLOT(displayMap()));
    button_map->setGeometry(QRect(QPoint(80, 210), QSize(71, 41)));

    QPixmap *pic = new QPixmap(":/images/bg1.jpg");

    output = new QLabel(this);
    output->setPixmap(pic->scaled(390, 230, Qt::KeepAspectRatio));
    output->setGeometry(QRect(QPoint(170, 20), QSize(391, 231)));
   // QPixmap *bot = new QPixmap(":/images/sprite.gif");
    QMovie *bot = new QMovie(":/images/sprite.gif");


    QLabel *bot_label = new QLabel(this);
    bot_label->setMovie(bot);
    bot_label->setGeometry(QRect(QPoint(260, 20), QSize(391, 231)));
    bot->start();


    player_items_list = new QListWidget(this);
    player_items_list->setGeometry(QRect(QPoint(20, 300), QSize(200, 100)));
    room_items_list = new QListWidget(this);
    room_items_list->setGeometry(QRect(QPoint(300, 300), QSize(200, 100)));

    QPushButton *button_drop_item = createButton("->", SLOT(dropItem()));
    button_drop_item->setGeometry(QRect(QPoint(225, 310), QSize(71, 41)));

    QPushButton *button_take_item = createButton("<-", SLOT(takeItem()));
    button_take_item->setGeometry(QRect(QPoint(225, 360), QSize(71, 41)));

    // setFont(*(new QFont("Papyrus", 8)));
    setGeometry(QRect(QPoint(200, 200), QSize(670, 450)));

    player_items.push_back(*(new Item("Ronut")));

    populateLists();
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

void ZorkUL::dropItem(){

    int index =  player_items_list->currentIndex().row();
    qDebug() << index;
    if(index != -1){
        Item  temp = player_items[index];
        qDebug() << temp.getLongDescription();
        player_items.erase(player_items.begin() + index);
        currentRoom->addItem(&temp);

        populateLists();

    }



}

void ZorkUL::takeItem(){
    int index =  room_items_list->currentIndex().row();
    qDebug() << index;
    if(index != -1){
        Item  temp = currentRoom->itemsInRoom[index];
        qDebug() << temp.getLongDescription();
        currentRoom->removeItem(index);
        player_items.push_back(temp);
        populateLists();
        //output->setPlainText( currentRoom->longDescription());
    }
}

void ZorkUL::populateLists(){
    player_items_list->clear();
    for( int i = 0; i < player_items.size(); i++){
        player_items_list->
                addItem(player_items[i].getShortDescription());
    }

    room_items_list->clear();
    for(int i = 0; i < currentRoom->itemsInRoom.size(); i++){
        room_items_list->
                addItem(currentRoom->itemsInRoom[i].getShortDescription());
    }
}

void ZorkUL::go(QString direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){}
        //output->setPlainText( currentRoom->longDescription());
    else
    {
        currentRoom = nextRoom;
      //  output->setPlainText( currentRoom->longDescription());
        populateLists();
    }
}

void ZorkUL::displayMap(){
    QString mapString = QString::fromStdString( "[h] --- [f] --- [g]\n\n"
                                                "[c] --- [a] --- [b]\n\n"
                                                "[i] --- [d] --- [e]\n");
    //output->setPlainText(mapString);
}

//Taken from Calculator Example
QPushButton *ZorkUL::createGoButton(const QString &text, const QString &direction)
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
