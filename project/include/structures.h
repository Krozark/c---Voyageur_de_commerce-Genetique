#ifndef STRUCTURES_H
#define STRUCTURE_H

#include <stdlib.h>

#define FIRST_BIT 0X80000000
#define LAST_BIT 0x00000001

inline double randMax(double fMax)
{
    return ((double)rand() / RAND_MAX)*fMax;
};

inline double randBorne(double fMin,double fMax)
{
    return fMin+((double)rand() / RAND_MAX)*(fMax-fMin);
};

inline double rand100()
{
    return ((double)rand() / RAND_MAX)*100.0L;
};

inline double rand1()
{
    return ((double)rand() / RAND_MAX);
};

/**
Structure permettant d'acceder au bits d'un octet
*/
typedef struct octet{
    char _0:1,
         _1:1,
         _2:1,
         _3:1,
         _4:1,
         _5:1,
         _6:1,
         _7:1;
} octet;

typedef struct _1octet{
    union{
        octet bit; //bit à bit
        unsigned char data; //par octet
    }u;
} _1octet;

typedef struct _2octet{
    union{
        octet bit[2]; //bit à bit
        unsigned char c[2]; // par octet
        short unsigned int data; //pour tout
    }u;
}_2octet;

typedef struct _4octet{
    union{
        octet bit[4]; // bit à bit
        unsigned char c[4]; //par octet
        short unsigned int si[2]; // par 2 octet
        long unsigned int data; //pour tout
    }u;
}_4octet;

typedef struct _8octet{
    union{
        octet bit[8]; //pour accet bit à bit
        unsigned char c[8]; //par octet
        short unsigned int si[4]; //par 2 octet
        long unsigned int li[2]; //par 4 octet
        long long unsigned int data;//pour tout
    }u;
}_8octet;



#endif
