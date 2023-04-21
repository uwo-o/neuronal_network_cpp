#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix.h"

/*
Transform struct
 - double slant: A slant value to be applied
 - double ** apply_function: Pointer that has the memory location of the transform function
*/
typedef struct Transform {
    double slant;
    double (*apply_function)(Neurone *, Matrix *, double, int);
} Transform;

double sigmoide(double x);
double apply_function(Neurone * vector, Matrix * matrix, double slant, int neurons_quantity);

#endif