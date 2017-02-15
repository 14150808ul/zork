#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>

namespace Ui
{
    class GameWindow; // Create a namespace to tell what is the User Interface
}

// inherits from QMainWindow
class GameWindow : public QMainWindow
{
    Q_OBJECT // this is used to use the slots and signals (events in qt)
    public:
        explicit GameWindow( QWidget * parent = 0 );
        ~GameWindow();
    void mouseMoveEvent(QMouseEvent *event);
    static int x;
private slots:
    void changeAnimation();
    void loseHealth();

private:
        Ui::GameWindow *ui; // private ui object to use the Window
        QTimer *timer;
        QPixmap *image, *image2, *image3, *image4;
};

#endif // GAMEWINDOW_H
