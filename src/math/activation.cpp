#include "math/activation.h"

double sigmoid(double x) {
     return 1/(1-exp(-x));
}

double d_sigmoid(double x) {
    return sigmoid(x)*(1-sigmoid(x));
}