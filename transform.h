#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix.h"

typedef struct Transform {
    double * dom;
    double slant;
} Transform;

double * apply_function(double * parents, Matrix * matrix, double slant);

#endif