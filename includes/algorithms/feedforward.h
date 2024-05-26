#ifndef FEEDFORWARD_H
#define FEEDFORWARD_H

#include <iostream>

#include "math/matrix.h"
#include "math/vector.h"

void feedforward(int layers, int *neurons, double **data, Matrix * weights, Matrix * biases, Vector **output);