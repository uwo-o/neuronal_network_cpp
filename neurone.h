#ifndef NEURONE_H
#define NEURONE_H

#include "matrix.h"
#include "transform.h"

typedef struct Neurone {
    double * parents;
    double * childrens;
    double layer;
} Neurone;

#endif