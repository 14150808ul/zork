#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_west_clicked()
{
    ui->output->setPlainText("West");
}

void MainWindow::on_button_east_clicked()
{
    ui->output->setPlainText("East");
}

void MainWindow::on_button_north_clicked()
{
    ui->output->setPlainText("North");
}

void MainWindow::on_button_south_clicked()
{
    ui->output->setPlainText("South");
}

