#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <cmath>

double ReLu(double);
double d_ReLu(double);

double sigmoid(double);
double d_sigmoid(double);

double linear(double);
double d_linear(double);

#endif