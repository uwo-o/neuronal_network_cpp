#ifndef NETWORK_H
#define NETWORK_H

#include "neurone.h"

typedef struct Network{
    int input_size;
    int output_size;
    int hidden_layers;
    int hidden_layer_size;
    Neurone * input_array;
    Neurone * output_array;
} Network;

#endif