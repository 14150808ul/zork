#include "zork.h"

Zork::Zork(int argc, char *argv[]) : QApplication(argc, argv), model(), view(), controller(&model, &view)
{
    view.show();
}
