#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <math.h>

#include "matrix.hpp"
#include "neuron.hpp"

/*
Transform class
 - double slant: A slant value to be applied
 - double ** apply_function: Pointer that has the memory location of the transform function
*/
class Transform {
    public:
        double slant;
        double (*apply_function)(Neuron *, Matrix *, double, int);
};

double sigmoide(double x);
double apply_function(Neuron * vector, Matrix * matrix, double slant, int neurons_quantity);

#endif