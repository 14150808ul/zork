#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Model model;
    View view;
    Controller(&model, &view);
    view.show();
    return a.exec();
}
