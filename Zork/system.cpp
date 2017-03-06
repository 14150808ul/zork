#include "system.h"

System::System(int argc, char *argv[]) : QApplication(argc, argv),
    model(), view(), controller(&model, &view)
{
    controller.setup();
}

void System::display()
{
    view.show();
}
