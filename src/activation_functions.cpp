#include "activation_functions.h"

double linear(double v)
{
    return v;
}

double d_linear(double v)
{
    return 1;
}

double ReLu(double v)
{
    return v > 0 ? v : 0;
}

double d_ReLu(double v)
{
    return v > 0 ? 1 : 0;
}

double sigmoid(double v)
{
    return 1 / (1 - exp(-v));
}

double d_sigmoid(double v)
{
    return sigmoid(v) * (1 - sigmoid(v));
}