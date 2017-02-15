#include "gamewindow.h"
#include "ui_gamewindow.h"


int GameWindow::x = 0;

GameWindow::GameWindow( QWidget * parent ) :QMainWindow( parent ), ui( new Ui::GameWindow )
{
    ui->setupUi( this ); // this connects to the ui form
    timer = new QTimer(this);

    connect(ui->pushButton, SIGNAL( clicked() ), this, SLOT( loseHealth() ) );
    connect( timer, SIGNAL( timeout() ), this, SLOT( changeAnimation() ) );

    image = new QPixmap( ":/images/doom1.jpg" );
    image2 = new QPixmap( ":/images/doom2.jpg" );
    image3 = new QPixmap( ":/images/doom1hurt.jpg" );
    image4 = new QPixmap( ":/images/doom2hurt.jpg" );

    ui->label->setPixmap( image->scaled( 150,150,Qt::KeepAspectRatio ) );
    timer->start( 300 );
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::loseHealth()
{
    if(ui->label_3->text() == "DOOM GUY LOST HEALTH")
    {
        ui->label_3->setText("DOOM GUY GAINS HEALTH");
        ui->pushButton->setText("LOSE HEALTH");
    }

    else
    {
      ui->label_3->setText("DOOM GUY LOST HEALTH");
      ui->pushButton->setText("GAIN HEALTH");
    }
}

void GameWindow::changeAnimation()
{
    if( x == 0 && ui->label_3->text() == "DOOM GUY GAINS HEALTH" )
    {
       ui->label->setPixmap( image->scaled(150,150,Qt::KeepAspectRatio) );
        x++;
    }

    else if (x == 1 && ui->label_3->text() == "DOOM GUY GAINS HEALTH")
    {
        ui->label->setPixmap( image2->scaled(150,150,Qt::KeepAspectRatio) );
        x--;
    }

    else if (x == 0 && ui->label_3->text() == "DOOM GUY LOST HEALTH")
    {
        ui->label->setPixmap( image3->scaled(150,150,Qt::KeepAspectRatio) );
        x++;
    }

    else if (x == 1 && ui->label_3->text() == "DOOM GUY LOST HEALTH")
    {
        ui->label->setPixmap( image4->scaled(150,150,Qt::KeepAspectRatio) );
        x--;
    }
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    if( event->x() > 1000 && event->y() > 50 )
    {
       qDebug() << event->pos();
    }
}

