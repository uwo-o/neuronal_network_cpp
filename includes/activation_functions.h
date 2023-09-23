#ifndef ACTIVATION_FUNCTIONS_HPP
#define ACTIVATION_FUNCTIONS_HPP

#include <cmath>

double ReLU(double x){return x > 0 ? x : 0;};
double sigmoide(double x){return 1/(1+exp(-x));};

#endif