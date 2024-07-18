#include "activation_functions.h"

float none(float v)
{
    return v;
}

float d_none(float v)
{
    return 1;
}

float ReLu(float v)
{
    return v > 0 ? v : 0;
}

float d_ReLu(float v)
{
    return 1;
}