#ifndef GRADIENT_H
#define GRADIENT_H

#include "vector.h"
#include "network.h"

class Gradient {
    private:
        double (*d_activation)(double);
        double learning_rate;

    public:
        Gradient(double (*d_activation)(double), double learning_rate);
        Vector ** calculate(Vector *current, Vector *prev, Vector *errors);
};

#endif