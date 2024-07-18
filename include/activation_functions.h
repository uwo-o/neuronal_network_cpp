#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <cmath>

float ReLu(float);
float d_ReLu(float);

float Sigmoid(float);
float d_Sigmoid(float);

float linear(float);
float d_linear(float);

#endif