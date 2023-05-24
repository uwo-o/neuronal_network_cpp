#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <cmath>

#include "matrix.hpp"
#include "neuron.hpp"

/*
Transform class
 - double bias: A slant value to be applied
 - double ** apply_function: Pointer that has the memory location of the transform function
*/
class Transform {
    public:
        double bias;
        double (*apply_function)(Neuron *, Matrix *, double, int);
};

double ReLU(double x);
double sigmoide(double x);
double apply_function(Neuron * vector, Matrix * matrix, double bias, int neurons_quantity);

#endif
