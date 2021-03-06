#ifndef BITARRAY_H
#define BITARRAY_H

#include "structures.h"

/**
Class metant en oeuvre des methode pour stoquer chaque bool sous la form d'un bit.
Ce n'est rien d'autre qu'un tableau de bit optimisé (à l'octet le plus proche du nessesaire).
l'operateur [] permet uniquement un accese en lecture, utiliser Set(int,int) pour un acces en ecriture.
*/
class BitArray
{
    public:
        BitArray();
        BitArray(unsigned int size);
        void ReplaceWith(const BitArray& other);
        void InverseWith(BitArray& other);
        ~BitArray();

        void Creat(unsigned int size);
        const bool operator[] (const unsigned int index);

        void Set(unsigned int index,bool value);

        void Inverse(BitArray& other,unsigned int from, unsigned int to);
        inline const unsigned int GetSize(){return size;};
        inline const unsigned int GetNombreChar(){return tableau__len;};
        void print();

        octet* tableau;
    private:
        unsigned int size; //valeur de l'élements max
        unsigned int tableau__len; //taille du tableau aloué
};

#endif // BITARRAY_H
