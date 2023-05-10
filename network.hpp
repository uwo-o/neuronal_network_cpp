#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>

#include "neuron.hpp"

typedef struct Network{
    int input_size;
    int output_size;
    int hidden_layers;
    int hidden_layer_size;
    Neuron * input_array;
    Neuron * output_array;
} Network;

void neurone_connector(Neuron * input_neurones, Neuron * output_neurones, Neuron * hidden_neurones, int input_size, int output_size, int hidden_layers, int hidden_layers_size);
Network * create_network(int input_size, int output_size, int hidden_layers, int hidden_layers_size);
Network * load_model(FILE * model);

#endif