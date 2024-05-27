#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

#include <iostream>

#include "activation_functions.h"
#include "math/gradient.h"
#include "math/matrix.h"
#include "math/vector.h"
#include "layer.h"


void backpropagation(int n_layers, int *neurons, Layer ** layers, Vector *errors, double learning_rate, int epochs);
#endif