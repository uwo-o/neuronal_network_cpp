#include "network.h"

Network::Network(int layers, double learning_rate, int input_size, int neurons_per_hlayer, int output_size) {
    this->layers = layers;
    this->network = new Layer*[layers];
    this->learning_rate = learning_rate;
    this->input_size = input_size;
    this->neurons_per_hlayer = neurons_per_hlayer;
    this->output_size = output_size;

    for (int i = 0; i < layers; i++) {
        if (i == 0) {
            this->network[i] = new Layer(i);
        } else if (i == layers - 1) {
            this->network[i] = new Layer(i, output_size, neurons_per_hlayer);
        } else {
            this->network[i] = new Layer(i, neurons_per_hlayer, input_size);
        }
    }
}

Network::~Network() {
    for (int i = 0; i < layers; i++) {
        delete this->network[i];
    }
    delete[] this->network;
}

void Network::set_name(char *name) {
    this->name = name;
}

char * Network::get_name() {
    return this->name;
}