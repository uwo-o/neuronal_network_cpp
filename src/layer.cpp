#include "layer.h"

Layer::Layer(int id, int neurons, int input_size) {
    this->id = id;
    this->biases = nullptr;
    this->weights = nullptr;
    
    this->neurons = new std::vector<double>(neurons);
    this->Z = new std::vector<double>(neurons);

    randomize_vector(this->neurons);
    randomize_vector(this->Z);

    if (id != 0) {
        this->biases = new std::vector<double>(neurons);
        randomize_vector(this->biases);
        this->weights = new std::vector<std::vector<double> *>(neurons);
        for (int i = 0; i < neurons; i++) {
            this->weights->at(i) = new std::vector<double>(input_size);
        }
        randomize_matrix(this->weights);
    }
}

Layer::~Layer() {
    delete this->neurons;
    delete this->biases;
    delete this->weights;
}

void Layer::set_input(std::vector<double> *input) {
    this->input = input;
}

void Layer::print() {
    std::cout << "----- Layer " << this->id << "-----\n"<< std::endl;
    
    if (this->weights != nullptr) {
        std::cout << "Weights: " << std::endl;
        for (int i = 0; i < this->weights->size(); i++) {
            for (int j = 0; j < this->weights->at(i)->size(); j++) {
                std::cout << this->weights->at(i)->at(j) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    
    if (this->biases != nullptr) {
        std::cout << "Biases: " << std::endl;
        for (int i = 0; i < this->biases->size(); i++) {
            std::cout << this->biases->at(i) << " ";
        }
        std::cout << "\n";
    }

    if (this->neurons !=nullptr) {
        std::cout << "Neurons: " << std::endl;
        for (int i = 0; i < this->neurons->size(); i++) {
            std::cout << this->neurons->at(i) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "==================\n";
}

int Layer::get_id() {
    return this->id;
}

std::vector<double> * Layer::get_biases() {
    return this->biases;
}

std::vector<std::vector<double> *> * Layer::get_weights() {
    return this->weights;
}

std::vector<double> * Layer::get_neurons() {
    return this->neurons;
}

void Layer::set_neurons(std::vector<double> * neurons) {
    if (neurons != nullptr)
        delete this->neurons;
    this->neurons = neurons;
}

void Layer::set_Z(std::vector<double> * Z) {
    if (Z != nullptr)
        delete this->Z;
    this->Z = Z;
}

std::vector<double> * Layer::get_Z() {
    return this->Z;
}