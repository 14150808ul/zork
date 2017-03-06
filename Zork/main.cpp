#include "system.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    System sys(argc,argv);
    sys.display();
    return sys.exec();
}
