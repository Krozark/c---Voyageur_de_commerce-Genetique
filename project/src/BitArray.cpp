#include "../include/BitArray.h"

#include <iostream>
using namespace std;

BitArray::BitArray()
{
    size=0;
    tableau=0;
    tableau__len=0;
};

BitArray::BitArray(unsigned int size)
{
    tableau=0;
    Creat(size);
};

void BitArray::ReplaceWith(const BitArray& other)
{
    if(tableau__len==other.tableau__len)
    {
        unsigned int u=0,i=0,bit=0;
        while(u<size)
        {
            switch (bit)
            {
                case 0: tableau[i]._0=other.tableau[i]._0;++bit;break;
                case 1: tableau[i]._1=other.tableau[i]._1;++bit;break;
                case 2: tableau[i]._2=other.tableau[i]._2;++bit;break;
                case 3: tableau[i]._3=other.tableau[i]._3;++bit;break;
                case 4: tableau[i]._4=other.tableau[i]._4;++bit;break;
                case 5: tableau[i]._5=other.tableau[i]._5;++bit;break;
                case 6: tableau[i]._6=other.tableau[i]._6;++bit;break;
                default: tableau[i]._7=other.tableau[i]._7;bit=0;++i;break;
            }
            ++u;
        }
    }
    else
    {
        cerr<<"Impossible de remplacer taille "<<tableau__len<<" par "<<other.tableau__len<<endl;
    }
};

BitArray::~BitArray()
{
    if(tableau)
        delete tableau;
};

void BitArray::Creat(unsigned int size)
{
    if(tableau__len>0)
        delete tableau;

    this->size=size;
    tableau__len=size>>3;

    if (size % 8 > 0)
        ++tableau__len;

    tableau=new octet[tableau__len];


};

const bool BitArray::operator[] (const unsigned int index)
{
    if (index >= size)
        return false;

    int unsigned i=index>>3;
    unsigned int bit = index % 8;

    switch (bit)
    {
        case 0: return tableau[i]._0;
        case 1: return tableau[i]._1;
        case 2: return tableau[i]._2;
        case 3: return tableau[i]._3;
        case 4: return tableau[i]._4;
        case 5: return tableau[i]._5;
        case 6: return tableau[i]._6;
        default: return tableau[i]._7;
    }
};

void BitArray::print()
{
    unsigned int u=0,i=0,bit=0;
    while(u<size)
    {
        switch (bit)
        {
            case 0: cout<<(bool)tableau[i]._0;++bit;break;
            case 1: cout<<(bool)tableau[i]._1;++bit;break;
            case 2: cout<<(bool)tableau[i]._2;++bit;break;
            case 3: cout<<(bool)tableau[i]._3;++bit;break;
            case 4: cout<<(bool)tableau[i]._4;++bit;break;
            case 5: cout<<(bool)tableau[i]._5;++bit;break;
            case 6: cout<<(bool)tableau[i]._6;++bit;break;
            default: cout<<(bool)tableau[i]._7<<" ";bit=0;++i;break;
        }
        ++u;
    }
    cout<<endl;
};

void BitArray::Inverse(BitArray& other,unsigned int from, unsigned int to)
{
    if (from > to)
        return;
    if (to> size || to > other.size)
        to = (size<other.size)?size:other.size;


    int unsigned i=from>>3;
    unsigned int bit = from % 8;

    const unsigned int i_to=to>>3;
    const unsigned int bit_to=to%8;

    while(i !=i_to || bit != bit_to)
    {
        bool current;
        switch (bit)
        {
            case 0: current=tableau[i]._0;
                    tableau[i]._0=other.tableau[i]._0;
                    other.tableau[i]._0=current;
                    ++bit;
                    break;

            case 1: current=tableau[i]._1;
                    tableau[i]._1=other.tableau[i]._1;
                    other.tableau[i]._1=current;
                    ++bit;
                    break;

            case 2: current=tableau[i]._2;
                    tableau[i]._2=other.tableau[i]._2;
                    other.tableau[i]._2=current;
                    ++bit;
                    break;

            case 3: current=tableau[i]._3;
                    tableau[i]._3=other.tableau[i]._3;
                    other.tableau[i]._3=current;
                    ++bit;
                    break;

            case 4: current=tableau[i]._4;
                    tableau[i]._4=other.tableau[i]._4;
                    other.tableau[i]._4=current;
                    ++bit;
                    break;
            case 5: current=tableau[i]._5;
                    tableau[i]._5=other.tableau[i]._5;
                    other.tableau[i]._5=current;
                    ++bit;
                    break;
            case 6: current=tableau[i]._6;
                    tableau[i]._6=other.tableau[i]._6;
                    other.tableau[i]._6=current;
                    ++bit;
                    break;
            default: current=tableau[i]._7;
                    tableau[i]._7=other.tableau[i]._7;
                    other.tableau[i]._7=current;
                    ++i;
                    bit=0;
                    break;
        }
    }
};

void BitArray::Set(unsigned int index,bool value)
{
    if (index >= size)
        return;

    int unsigned i=index>>3;
    unsigned int bit = index % 8;

    switch (bit)
    {
        case 0: tableau[i]._0=value;break;
        case 1: tableau[i]._1=value;break;
        case 2: tableau[i]._2=value;break;
        case 3: tableau[i]._3=value;break;
        case 4: tableau[i]._4=value;break;
        case 5: tableau[i]._5=value;break;
        case 6: tableau[i]._6=value;break;
        default: tableau[i]._7=value;break;
    }
};

void BitArray::InverseWith(BitArray& other)
{
    octet* t=other.tableau;
    other.tableau=tableau;
    tableau=t;

    unsigned int i=other.size;
    other.size=size;
    size=i;

    i=other.tableau__len;
    other.tableau__len=tableau__len;
    tableau__len=i;
};
