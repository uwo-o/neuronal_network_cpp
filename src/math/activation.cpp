#include "math/activation.h"

double sigmoid(double x) {
     return 1/(1-exp(-x));
}

double d_sigmoid(double x) {
    return sigmoid(x)*(1-sigmoid(x));
}

double relu(double x) {
    return x > 0 ? x : 0;
}

double d_relu(double x) {
    return x > 0 ? 1 : 0;
}

double linear(double x) {
    return x;
}

double d_linear(double x) {
    return 1;
}

double tanh(double x) {
    return std::tanh(x);
}

double d_tanh(double x) {
    return 1 - std::pow(tanh(x), 2);
}