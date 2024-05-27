#ifndef ACTIVATION_FUNCTIONS_HPP
#define ACTIVATION_FUNCTIONS_HPP

#include <cmath>

double ReLU(double x){return x > 0 ? x : 0;};
double dReLU(double x){return x > 0 ? 1 : 0;};

double sigmoide(double x){return 1/(1+exp(-x));};
double dsigmoide(double x){return sigmoide(x)*(1-sigmoide(x));};

#endif