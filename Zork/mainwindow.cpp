#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Zork()
{
    ui->setupUi(this);
    //QPushButton *button = new QPushButton("&TEST", this);
    populateLists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_west_clicked()
{
    QString result = QString::fromStdString( Zork.go("west") );
    ui->output->setPlainText(result);
    populateLists();
}

void MainWindow::on_button_east_clicked()
{
    QString result = QString::fromStdString( Zork.go("east") );
    ui->output->setPlainText(result);
    populateLists();
}

void MainWindow::on_button_north_clicked()
{
    QString result = QString::fromStdString( Zork.go("north") );
    ui->output->setPlainText(result);
    populateLists();
}

void MainWindow::on_button_south_clicked()
{
    QString result = QString::fromStdString( Zork.go("south") );
    ui->output->setPlainText(result);
    populateLists();
}


void MainWindow::on_button_map_clicked()
{
    QString result = QString::fromStdString( "[h] --- [f] --- [g]\n\n"
                                             "[c] --- [a] --- [b]\n\n"
                                             "[i] --- [d] --- [e]\n");
    ui->output->setPlainText(result);
}

void MainWindow::populateLists(){
    ui->player_items_list->clear();
    for( int i = 0; i < Zork.player->playerItems.size(); i++){
        ui->player_items_list->
                addItem(QString::fromStdString(Zork.player->playerItems[i].getShortDescription()));
    }


    ui->room_items_list->clear();
  //ui->player_items_list->addItem("Test");
    for(int i = 0; i < Zork.currentRoom->itemsInRoom.size(); i++){
        ui->room_items_list->
                addItem(QString::fromStdString(Zork.currentRoom->itemsInRoom[i].getShortDescription()));
    }
}

void MainWindow::on_button_item_put_clicked()
{
    //Remove Item from player and add to Current Room
}
