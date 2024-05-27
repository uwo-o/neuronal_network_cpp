#include "layer.h"

Layer::Layer(int id, int neurons, int input_size, double (*activation)(double)) {
    this->id = id;
    this->biases = nullptr;
    this->weights = nullptr;
    this->activation = nullptr;

    this->neurons = new Vector(neurons);
    if (input_size!=-1) {
        this->biases = new Vector(neurons);
        this->weights = new Matrix(neurons, input_size);
        this->activation = activation;
    }
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

void Layer::print() {
    std::cout << "Layer " << this->id << std::endl;
    std::cout << "Neurons: " << std::endl;
    this->neurons->print();
    
    if (this->weights != nullptr) {
        std::cout << "Weights: " << std::endl;
        this->weights->print();
    }
    
    if (this->biases != nullptr) {
        std::cout << "Biases: " << std::endl;
        this->biases->print();
    }
}