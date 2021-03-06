#ifndef VILLES_H
#define VILLES_H

#include <math.h>
#include "Voyageur.h"

class Villes
{
    public:
        Villes(unsigned int Nombre);
        ~Villes();
        void Start(unsigned int nb_voyageur,unsigned int iteration_max);
        void Evaluate(Voyageur& voy);

    private:
        unsigned int size;
        float** d;
        float** pos;
        float best;
};

#endif // VILLES_H
