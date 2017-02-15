#include "gamewindow.h"
#include <QApplication>

// Zork is an Application which has a window object
class ZorkGame: public QApplication
{
    public:
        ZorkGame( int argc, char * argv[] ): QApplication( argc, argv )
        {
           window = new GameWindow();
           window->show();
        }
        ~ZorkGame()
        {
            delete window;
        }
    private:
        GameWindow * window; // soon as it is created on the stack will vanish like a constructor call or function call
};

int main( int argc, char * argv[] )
{
    return ZorkGame( argc, argv ).exec();
}
