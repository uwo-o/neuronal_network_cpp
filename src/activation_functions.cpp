#include "activation_functions.h"

float linear(float v)
{
    return v;
}

float d_linear(float v)
{
    return 1;
}

float ReLu(float v)
{
    return v > 0 ? v : 0;
}

float d_ReLu(float v)
{
    return v > 0 ? 1 : 0;
}