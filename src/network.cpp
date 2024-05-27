#include "network.h"

Network::Network(double learning_rate, int input_size, int hlayers_size, int output_size, double (*activation)(double)) {
    this->network = new Layer*[hlayers_size + 2];
    this->learning_rate = learning_rate;
    this->input_size = input_size;
    this->hlayers_size = hlayers_size;
    this->output_size = output_size;
    this->activation = activation;
    this->name = nullptr;

    for (int i = 0; i < hlayers_size + 2; i++) {
        if (i == 0) {
            this->network[i] = new Layer(i, input_size, -1, activation);
        } else if (i == hlayers_size + 1) {
            this->network[i] = new Layer(i, output_size, input_size, activation);
        } else {
            this->network[i] = new Layer(i, input_size, input_size, activation);
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

void Network::describe() {
    std::cout << "Network: " << this->name << std::endl;
    std::cout << "Input size: " << this->input_size << std::endl;
    std::cout << "Hidden layers: " << this->hlayers_size << std::endl;
    std::cout << "Output size: " << this->output_size << std::endl;
    std::cout << "Learning rate: " << this->learning_rate << std::endl;
}

void Network::full_describe() {
    this->describe();
    for (int i = 0; i < hlayers_size + 2; i++) {
        this->network[i]->print();
    }
}

Layer * Network::get_layer(int id) {
    return this->network[id];
}