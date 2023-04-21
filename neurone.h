#ifndef NEURONE_H
#define NEURONE_H

#include "matrix.h"
#include "transform.h"

/*
Neurone struct
- int childrens_quantity: The children's array size 
- Neurone * childrens: Pointer that has the Neuone array
- double value: The neurone's value
- int layer_id: The layer deeps number
*/
typedef struct Neurone {
    int childrens_quantity;
    Neurone * childrens;
    double value;
    int layer_id;
} Neurone;

#endif