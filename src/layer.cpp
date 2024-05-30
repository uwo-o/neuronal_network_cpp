#include "layer.h"

Layer::Layer(int id, int neurons, int input_size) {
    this->id = id;
    this->biases = nullptr;
    this->weights = nullptr;

    this->neurons = new Vector(neurons);

    this->biases = new Vector(neurons);
    this->weights = new Matrix(neurons, input_size);
}

Layer::~Layer() {
    delete this->neurons;
    delete this->biases;
    delete this->weights;
}

void Layer::set_input(Vector *input) {
    this->input = input;
}

void Layer::print() {
    std::cout << "----- Layer " << this->id << "-----\n"<< std::endl;
    
    if (this->weights != nullptr) {
        std::cout << "Weights: " << std::endl;
        this->weights->print();
        std::cout << "\n";
    }
    
    if (this->biases != nullptr) {
        std::cout << "Biases: " << std::endl;
        this->biases->print();
        std::cout << "\n";
    }

    if (this->neurons !=nullptr) {
        std::cout << "Neurons: " << std::endl;
        this->neurons->print();
        std::cout << "\n";
    }

    std::cout << "==================\n";
}

Vector * Layer::get_biases() {
    return this->biases;
}

Matrix * Layer::get_weights() {
    return this->weights;
}

Vector * Layer::get_neurons() {
    return this->neurons;
}