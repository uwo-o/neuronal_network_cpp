#include "model.h"

Model::Model(std::string name, double input_neurons, double hidden_neurons, double hidden_layers, double output_neurons, double learning_rate){
    this->network = new Network(input_neurons, hidden_neurons, hidden_layers, output_neurons, learning_rate);
    this->network->set_name(name);
    this->learning_rate = learning_rate;
}

Model::~Model(){
    delete this->network;
}

void Model::set_d_activation(double (*d_activation)(double)){
    this->network->set_d_activation(d_activation);
}

void Model::set_activation(double (*activation)(double)){
    this->network->set_activation(activation);
}

void Model::train(Data * data, int epochs){

    std::cout << "Training model: " << this->network->get_name() << std::endl;
    std::cout << "Learning rate: " << this->learning_rate << std::endl;
    std::cout << "Epochs: " << epochs << std::endl;
    std::cout << "Data size: " << data->size << std::endl;
    std::cout << "====================================" << std::endl;

    for (int i = 0; i < epochs; i++){

        std::cout << "Epoch: " << i + 1 << "/" << epochs << ":" << std::endl;

        for (int j = 0; j < data->size; j++){
            run_feedforward(this->network, data->inputs->at(j));
            backpropagation(this->network, data->expected, this->learning_rate);
        }
    }
}

std::vector<double> * Model::predict(std::vector<double> * input){
    return run_feedforward(this->network, input);
}