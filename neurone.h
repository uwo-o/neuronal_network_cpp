#ifndef NEURONE_H
#define NEURONE_H

/*
Neurone struct
- int childrens_quantity: The children's array size 
- Neurone * childrens: Pointer that has the Neuone array
- double value: The neurone's value
- int layer_id: The layer deeps number
*/
typedef struct Neurone {
    int parents_quantity;
    int childrens_quantity;
    struct Neurone * parents;
    struct Neurone * childrens;
    double value;
    int layer_id;
} Neurone;

#endif