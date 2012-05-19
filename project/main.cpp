#include "include/Villes.h"
#include <iostream>


int main()
{
    srand(time(NULL));

    Villes ville_t(100);
    ville_t.Start(500,100);

    return 0;
}
