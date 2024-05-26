#ifndef BACK_PROPAGATION_H
#define BACK_PROPAGATION_H

#include <iostream>

#include "math/matrix.h"
#include "math/vector.h"

void backpropagation(int layers, int *neurons, double **data, Matrix * weights, Matrix * biases, Vector **expected, double learning_rate, int epochs);

#endif