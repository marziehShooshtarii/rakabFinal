#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Control.hpp"

int main()
{
    srand(unsigned(time(NULL)));
    Control c;
    c.run();
}
