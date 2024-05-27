#include "layer.h"

Layer::Layer(int id, int neurons, int input_size, double (*activation)(double)) {
    this->id = id;
    this->neurons = new Vector(neurons);
    this->biases = new Vector(neurons);
    this->weights = new Matrix(neurons, input_size);
    this->activation = activation;
}

Layer::~Layer() {
    delete this->neurons;
    delete this->biases;
    delete this->weights;
}

void Layer::set_input(Vector *input) {
    this->input = input;
}

Vector * Layer::get_output() {
    if (this->input == NULL) {
        std::cerr << "Layer " << this->id << " has no input set" << std::endl;
        return NULL;
    }

    delete this->neurons;
    neurons = this->weights->mult(this->input);
    neurons->add(this->biases);
    neurons->apply(this->activation);

    return this->neurons;
}

