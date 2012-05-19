#ifndef VOYAGEUR_H
#define VOYAGEUR_H

#include "BitArray.h"
#include <vector>

class Voyageur
{
    public:
        Voyageur(unsigned int nb_villes=0);
        void ReplaceWith(const Voyageur& other);


        void Creat(unsigned int nb_villes);
        unsigned int Get(unsigned int index);
        void Set(unsigned int index,unsigned int value);
        void InverseWith(Voyageur& other);

        unsigned int* Get();

        void InitWith(std::vector<unsigned int> v);

        void Inverse(Voyageur& other,unsigned int from, unsigned int to);
        void Inverse(unsigned int from, unsigned int to);

        void print(){bit_array.print();};
        void print(unsigned int index);

        unsigned int Size(){return nb_elem;};

        float distance;

        bool operator <(const Voyageur& other){return distance <other.distance;};
        bool operator >(const Voyageur& other){return distance >other.distance;};

    private:
        unsigned int nb_elem; //valeur de l'élements max
        unsigned char size_of_one; //  en bits
        BitArray bit_array;
};

#endif // VOYAGEUR_H
