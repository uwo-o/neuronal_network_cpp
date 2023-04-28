#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>
#include <stdlib.h>

#include "neurone.h"

typedef struct Network{
    int input_size;
    int output_size;
    int hidden_layers;
    int hidden_layer_size;
    Neurone * input_array;
    Neurone * output_array;
} Network;

void neurone_connector(Neurone * input_neurones, Neurone * output_neurones, Neurone * hidden_neurones, int input_size, int output_size, int hidden_layers, int hidden_layers_size);
Network * create_network(int input_size, int output_size, int hidden_layers, int hidden_layers_size);
Network * load_model(FILE * model);

#endif