#include "view.h"
#include <QMovie>

View::View(QWidget* parent) : QWidget(parent), signal_mapper(), background_label(new QLabel(this)), enemy_label(new QLabel(this)),
    room_item_display(new QListWidget(this)),player_item_display(new QListWidget(this)),
    drop_button(new QPushButton(">",this)), take_button(new QPushButton("<",this)),
    attack_button(new QPushButton("attack",this))
{
    setFixedSize(800, 600);
    createWidgets();
    setWidgetPos();
    connect(drop_button, SIGNAL(pressed()), this, SLOT(updateRoomItems()));
    connect(take_button, SIGNAL(pressed()), this, SLOT(updatePlayerItems()));
    connect(attack_button, SIGNAL(pressed()), this, SIGNAL(attackEnemy()));
}

View::~View()
{
    delete drop_button, delete take_button;
    delete room_item_display, delete player_item_display;
    delete background_label;
    background_label = nullptr;
    room_item_display = player_item_display = nullptr;
    drop_button = take_button = nullptr;

    for(int i = 0; i <4;i++)
    {
        delete buttons[i];
        buttons[i] = nullptr;
    }
}

void View::setWidgetPos()
{

    background_images[0] = new QPixmap(":/images/bg1.jpg");
    background_images[1] = new QPixmap(":/images/bg2.PNG");
    background_images[2] = new QPixmap(":/images/bg3.jpg");
    background_images[3] = new QPixmap(":/images/bg4.PNG");
    background_images[4] = new QPixmap(":/images/bg5.PNG");
    background_images[5] = new QPixmap(":/images/bg6.PNG");
    background_images[6] = new QPixmap(":/images/bg7.PNG");
    background_images[7] = new QPixmap(":/images/bg8.jpg");
    background_images[8] = new QPixmap(":/images/bg9.PNG");
    enemy_image = new QMovie(":/images/enemy.gif");
    background_label->setGeometry(170, 20, 391, 231);
    enemy_label->setGeometry(250, 45, 391, 231);
    background_label->setPixmap(background_images[4]->scaled(390,230));
    enemy_label->setMovie(enemy_image);
        enemy_image->start();
    buttons[0]->setGeometry(60, 0, 41, 51);
    buttons[1]->setGeometry(60, 90, 41, 51);
    buttons[2]->setGeometry(100, 50, 51, 41);
    buttons[3]->setGeometry(10, 50, 51, 41);
    room_item_display->setGeometry(300, 300, 200, 100);
    player_item_display->setGeometry(20, 300, 200, 100);
    drop_button->setGeometry(225,310,71,41);
    take_button->setGeometry(225,360,71,41);
    attack_button->setGeometry(50, 200, 71, 41);
}

void View::disableAttack(bool dead)
{
    attack_button->setEnabled(dead);
    enemy_label->setVisible(dead);
}

void View::populateList(const std::vector<Item*>& room_items, const std::vector<Item*>& player_items)
{
   room_item_display->clear();
   player_item_display->clear();

   for(unsigned int i = 0; i < room_items.size();i++)
       room_item_display->addItem(room_items[i]->getDescription());

   for(unsigned int i = 0; i < player_items.size();i++)
       player_item_display->addItem(player_items[i]->getDescription());
}

void View::updateRoomButtons(const unsigned char exits, int room)
{
    for(unsigned char i = 0, j = 1; i < 4; i++, j <<=1)
        buttons[i]->setEnabled((exits & j) == 0 ? true : false);

    background_label->setPixmap(background_images[room-1]->scaled(390,230));
}

void View::createWidgets()
{
    int direction_numbers[4] = {+3,-3,+1,-1};
    QString directions[4] = {"North","South","East","West"};

    for (int i = 0; i < 4; i++)
    {
        buttons[i] = new QPushButton(directions[i], this);
        connect(buttons[i],SIGNAL(pressed()), &signal_mapper, SLOT(map()));
        signal_mapper.setMapping(buttons[i],direction_numbers[i]);
    }
    connect(&signal_mapper, SIGNAL(mapped(int)), this, SIGNAL(updateRoom(int)));
}

void View::updatePlayerItems()
{
    if(room_item_display->currentIndex().row() != -1) // will crash otherwise if don't do a check
        emit updateCurrentPlayerItems(room_item_display->currentIndex().row());
}

void View::updateRoomItems()
{
    if (player_item_display->currentIndex().row() != -1)
        emit updateCurrentRoomItems(player_item_display->currentIndex().row());
}
