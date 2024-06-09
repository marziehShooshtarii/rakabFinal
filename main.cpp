#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "dealing.hpp"
int main ()
{
    srand(unsigned(time(NULL)));
    dealingCards r;
    r.setDealing();
    r.shuffelingCards();
    r.validateIdentity();
    r.randomCardSet();
    return 1;
}
