#include <QApplication>
#include "ZorkUL.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZorkUL zork;
    zork.show();
    return a.exec();
}
