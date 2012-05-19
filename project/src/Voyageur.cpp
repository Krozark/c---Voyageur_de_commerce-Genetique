#include "../include/Voyageur.h"

#include <iostream>
using namespace std;

Voyageur::Voyageur(unsigned int nb_villes)
{
    if(nb_villes>0)
        Creat(nb_villes);
    else
    {
        size_of_one=0;
        nb_elem=0;
    }
};

void Voyageur::ReplaceWith(const Voyageur& other)
{
    distance=other.distance;

    bit_array.ReplaceWith(other.bit_array);
    size_of_one=other.size_of_one;
    nb_elem=other.nb_elem;
}

void Voyageur::Creat(unsigned int nb_villes)
{
    if ((nb_elem = nb_villes)==0)
    {
        size_of_one=0;
        return;
    }
    --nb_villes;
    size_of_one=0;

    do
    {
        ++size_of_one;
    }while((nb_villes >>= 1) > 0);

    bit_array.Creat(size_of_one*nb_elem);

}


void Voyageur::InitWith(vector<unsigned int> v)
{
    unsigned int size=v.size();
    if(nb_elem<size)
        size=nb_elem;
    unsigned int i=0;
    while(i<size)
    {
        Set(i,v[i]);
        ++i;
    }
    while(i<nb_elem)
    {
        Set(i++,0);
    }
};

void Voyageur::Set(unsigned int index,unsigned int value)
{
    if (value >=nb_elem)
        return;
    index*=size_of_one;
    int unsigned i=index>>3;
    unsigned int bit = index % 8;

    for (unsigned int u=0;u<size_of_one;++u)
    {
        bool val = (value>>u) & LAST_BIT;
        switch (bit)
        {
            case 0: bit_array.tableau[i]._0=val;++bit;break;
            case 1: bit_array.tableau[i]._1=val;++bit;break;
            case 2: bit_array.tableau[i]._2=val;++bit;break;
            case 3: bit_array.tableau[i]._3=val;++bit;break;
            case 4: bit_array.tableau[i]._4=val;++bit;break;
            case 5: bit_array.tableau[i]._5=val;++bit;break;
            case 6: bit_array.tableau[i]._6=val;++bit;break;
            default: bit_array.tableau[i]._7=val;bit=0;++i;break;
        }
    }
};

unsigned int Voyageur::Get(unsigned int index)
{
    index=(index+1)*size_of_one-1;
    int unsigned i=index>>3;
    unsigned int bit = index % 8;
    unsigned int res=0,u=0;
    bool val;

    while(u<size_of_one)
    {
        res<<=1;
        switch (bit)
        {
            case 0: val=bit_array.tableau[i]._0;bit=7;--i;;break;
            case 1: val=bit_array.tableau[i]._1;--bit;break;
            case 2: val=bit_array.tableau[i]._2;--bit;break;
            case 3: val=bit_array.tableau[i]._3;--bit;break;
            case 4: val=bit_array.tableau[i]._4;--bit;break;
            case 5: val=bit_array.tableau[i]._5;--bit;break;
            case 6: val=bit_array.tableau[i]._6;--bit;break;
            default: val=bit_array.tableau[i]._7;--bit;break;
        }

        res|=val&LAST_BIT;
        ++u;
    }

    return res;
};

void Voyageur::print(unsigned int index)//begin by 0
{
    index*=size_of_one;
    unsigned int u=0,
                 i=index>>3,
                 bit=index%8;

    while(u<size_of_one)
    {
      switch (bit)
        {
            case 0: cout<<(bool)bit_array.tableau[i]._0;++bit;break;
            case 1: cout<<(bool)bit_array.tableau[i]._1;++bit;break;
            case 2: cout<<(bool)bit_array.tableau[i]._2;++bit;break;
            case 3: cout<<(bool)bit_array.tableau[i]._3;++bit;break;
            case 4: cout<<(bool)bit_array.tableau[i]._4;++bit;break;
            case 5: cout<<(bool)bit_array.tableau[i]._5;++bit;break;
            case 6: cout<<(bool)bit_array.tableau[i]._6;++bit;break;
            default: cout<<(bool)bit_array.tableau[i]._7<<" ";bit=0;++i;break;
        }
        ++u;
    }
    cout<<endl;
};

void Voyageur::Inverse(Voyageur& other,unsigned int index_from, unsigned int index_to)
{
    if (index_from > index_to)
        return;
    if (index_to> nb_elem ||index_to > other.nb_elem)
        index_to= (nb_elem<other.nb_elem)?nb_elem:other.nb_elem;

    index_from*=size_of_one;
    index_to*=size_of_one;
    int unsigned i=index_from>>3;
    unsigned int bit = index_from % 8;

    const unsigned int i_to=index_to>>3;
    const unsigned int bit_to=index_to%8;

    while(i !=i_to || bit != bit_to)
    {
        bool current;
        switch (bit)
        {
            case 0: current=bit_array.tableau[i]._0;
                    bit_array.tableau[i]._0=other.bit_array.tableau[i]._0;
                    other.bit_array.tableau[i]._0=current;
                    ++bit;
                    break;

            case 1: current=bit_array.tableau[i]._1;
                    bit_array.tableau[i]._1=other.bit_array.tableau[i]._1;
                    other.bit_array.tableau[i]._1=current;
                    ++bit;
                    break;

            case 2: current=bit_array.tableau[i]._2;
                    bit_array.tableau[i]._2=other.bit_array.tableau[i]._2;
                    other.bit_array.tableau[i]._2=current;
                    ++bit;
                    break;

            case 3: current=bit_array.tableau[i]._3;
                    bit_array.tableau[i]._3=other.bit_array.tableau[i]._3;
                    other.bit_array.tableau[i]._3=current;
                    ++bit;
                    break;

            case 4: current=bit_array.tableau[i]._4;
                    bit_array.tableau[i]._4=other.bit_array.tableau[i]._4;
                    other.bit_array.tableau[i]._4=current;
                    ++bit;
                    break;
            case 5: current=bit_array.tableau[i]._5;
                    bit_array.tableau[i]._5=other.bit_array.tableau[i]._5;
                    other.bit_array.tableau[i]._5=current;
                    ++bit;
                    break;
            case 6: current=bit_array.tableau[i]._6;
                    bit_array.tableau[i]._6=other.bit_array.tableau[i]._6;
                    other.bit_array.tableau[i]._6=current;
                    ++bit;
                    break;
            default: current=bit_array.tableau[i]._7;
                    bit_array.tableau[i]._7=other.bit_array.tableau[i]._7;
                    other.bit_array.tableau[i]._7=current;
                    ++i;
                    bit=0;
                    break;
        }
    }
    unsigned int* nb[2];
    nb[0]=Get();
    nb[1]=other.Get();
    string sm,st;
    vector<unsigned int> position[2][nb_elem];
    for(unsigned int i=0;i<nb_elem;++i)
    {
        position[0][nb[0][i]].push_back(i);
        position[1][nb[1][i]].push_back(i);
    }

    for(unsigned int i=0;i<nb_elem;i++)
    {
        if (position[0][i].size()>1)
        {
            unsigned int val=0;
            bool find=false;
            for(unsigned int j=0;j<nb_elem && !find;++j)
            {
                if (position[1][j].size()>1)
                {
                    find=true;
                    unsigned int index_l=position[1][j][1];
                    position[1][j].clear();
                    other.Set(index_l,i);
                    val=j;
                }
            }
            Set(position[0][i][1],val);
            position[0][i].clear();
        }
    }

    delete nb[0];
    delete nb[1];

};

void Voyageur::InverseWith(Voyageur& other)
{
    unsigned int i=other.nb_elem;
    other.nb_elem=nb_elem;
    nb_elem=i;

    i=other.size_of_one;
    other.size_of_one=size_of_one;
    size_of_one=i;

    float d=other.distance;
    other.distance=distance;
    distance=d;

    other.bit_array.InverseWith(bit_array);
};

unsigned int* Voyageur::Get()
{
    unsigned int* res=new unsigned int[nb_elem];

    unsigned int to=bit_array.GetSize()-1;
    int unsigned i=(to)>>3,
                 bit =(to)%8,
                 u=0;
    int nb=nb_elem-1;

    bool val;

    while(nb>=0)
    {
        res[nb]=0;
        u=0;
        while(u<size_of_one)
        {
            res[nb]<<=1;
            switch (bit)
            {
                case 0: val=bit_array.tableau[i]._0;bit=7;--i;break;
                case 1: val=bit_array.tableau[i]._1;--bit;break;
                case 2: val=bit_array.tableau[i]._2;--bit;break;
                case 3: val=bit_array.tableau[i]._3;--bit;break;
                case 4: val=bit_array.tableau[i]._4;--bit;break;
                case 5: val=bit_array.tableau[i]._5;--bit;break;
                case 6: val=bit_array.tableau[i]._6;--bit;break;
                default: val=bit_array.tableau[i]._7;--bit;break;
            }
            res[nb]|=val&LAST_BIT;
            ++u;
        }
        --nb;
    }
    return res;
};

void Voyageur::Inverse(unsigned int from, unsigned int to)
{
    unsigned int c=Get(from);
    Set(from,Get(to));
    Set(to,c);
};

