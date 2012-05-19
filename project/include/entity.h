#ifndef ENTITY_H
#define ENTITY_H

#include "BitArray.h"

class entity
{
    public:
        entity();
        ~entity();

    protected:

        BitArray data;

        unsigned long int demie_vie;
        unsigned long int vie;
        unsigned long int qt_bouffe;
        unsigned long int reserve;
        unsigned short int sans_manger;
    private:


};

#endif // ENTITY_H
