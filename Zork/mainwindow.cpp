#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Zork()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_west_clicked()
{
    QString result = QString::fromStdString( Zork.go("west") );
    ui->output->setPlainText(result);
}

void MainWindow::on_button_east_clicked()
{
    QString result = QString::fromStdString( Zork.go("east") );
    ui->output->setPlainText(result);
}

void MainWindow::on_button_north_clicked()
{
    QString result = QString::fromStdString( Zork.go("north") );
    ui->output->setPlainText(result);
}

void MainWindow::on_button_south_clicked()
{
    QString result = QString::fromStdString( Zork.go("south") );
    ui->output->setPlainText(result);
}

