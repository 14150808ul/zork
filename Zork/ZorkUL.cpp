#include <QtWidgets>
#include "ZorkUL.h"
using namespace std;

ZorkUL::ZorkUL(QWidget *parent)
    : QWidget(parent)
{
    createRooms();
    player_items.push_back((new Item("Ronut")));
    createGUI();
    populateLists();
    updateBot();
}

//Creates rooms and adds items/bots
void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;

    a = new Room("a");
    a->addItem(new Item("Blue key"));
    a->setBot(new QMovie(":/images/sprite.gif"));

    b = new Room("b");
    b->addItem(new Item("Red key"));
    c = new Room("c");
    c->addItem(new Item("Green key"));
    c->addItem(new Item("GroundHog"));
    d = new Room("d");
        d->addItem(new Item("Yellow key"));
    e = new Room("e");
        e->addItem(new Item("Orange key"));
            e->setBot(new QMovie(":/images/Bender.gif"));
    f = new Room("f");
        f->addItem(new Item("White key"));
    g = new Room("g");
        g->addItem(new Item("Black key"));
    h = new Room("h");
        h->addItem(new Item("Purple key"));
    i = new Room("i");
    i->addItem(new Item("Gold key"));

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

//Creates the ui elements
void ZorkUL::createGUI(){

    //Create direction buttons
    QPushButton *button_north = createGoButton("N", "north");
    button_north->setGeometry(QRect(QPoint(60, 0), QSize(41, 51)));
    QPushButton *button_south = createGoButton("S", "south");
    button_south->setGeometry(QRect(QPoint(60, 90), QSize(41, 51)));
    QPushButton *button_east = createGoButton("E", "east");
    button_east->setGeometry(QRect(QPoint(100, 50), QSize(51, 41)));
    QPushButton *button_west = createGoButton("W","west");
    button_west->setGeometry(QRect(QPoint(10, 50), QSize(51, 41)));

    //Create map button
  //  QPushButton *button_map = createButton("Map", SLOT(displayMap()));
  // button_map->setGeometry(QRect(QPoint(80, 210), QSize(71, 41)));

    //Background Image for room
    QPixmap *pic = new QPixmap(":/images/bg1.jpg");
    output = new QLabel(this);
    output->setPixmap(pic->scaled(390, 230, Qt::KeepAspectRatio));
    output->setGeometry(QRect(QPoint(170, 20), QSize(391, 231)));

    //Character/enemy sprite

    bot_label = new QLabel(this);
    bot_label->setGeometry(QRect(QPoint(260, 20), QSize(391, 231)));

    //Item lists
    player_items_list = new QListWidget(this);
    player_items_list->setGeometry(QRect(QPoint(20, 300), QSize(200, 100)));
    room_items_list = new QListWidget(this);
    room_items_list->setGeometry(QRect(QPoint(300, 300), QSize(200, 100)));

    //Take/Drop buttons
    QPushButton *button_drop_item = createButton("->", SLOT(dropItem()));
    button_drop_item->setGeometry(QRect(QPoint(225, 310), QSize(71, 41)));
    QPushButton *button_take_item = createButton("<-", SLOT(takeItem()));
    button_take_item->setGeometry(QRect(QPoint(225, 360), QSize(71, 41)));

     //setFont(*(new QFont("Papyrus", 8)));

    //Set window size
    setGeometry(QRect(QPoint(200, 200), QSize(670, 450)));
}

void ZorkUL::dropItem(){

    int index =  player_items_list->currentIndex().row();
    qDebug() << index;
    if(index != -1){
        Item* temp = player_items[index];
        qDebug() << temp->getDescription();
        player_items.erase(player_items.begin() + index);
        currentRoom->addItem(temp);

        populateLists();

    }
}

void ZorkUL::takeItem(){
    int index =  room_items_list->currentIndex().row();
    qDebug() << index;
    if(index != -1){
        Item*  temp = currentRoom->getItemsInRoom()[index];
        qDebug() << temp->getDescription();
        currentRoom->removeItem(index);
        player_items.push_back(temp);

        //currentRoom >> player
        populateLists();
        //output->setPlainText( currentRoom->longDescription());
    }
}

//update item lists
void ZorkUL::populateLists(){
    player_items_list->clear();
    for( int i = 0; i < player_items.size(); i++){
        player_items_list->
                addItem(player_items[i]->getDescription());
    }

    room_items_list->clear();
    for(int i = 0; i < currentRoom->getItemsInRoom().size(); i++){
        room_items_list->
                addItem(currentRoom->getItemsInRoom()[i]->getDescription());
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
        updateBot();
    }
}

void ZorkUL::updateBot(){
    QMovie *bot = currentRoom->getBot();

    if( bot )
    {
        bot_label->setMovie(bot);
        bot->start();
        bot_label->show();
    }
    else{
        bot_label->hide();
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
