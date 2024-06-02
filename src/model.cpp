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

void Model::train(std::list<Vector *> * input_set, std::list<Vector *> * expected_set, int epochs){
    for(int i = 0; i < epochs; i++){
        for(auto input = input_set->begin(), expected = expected_set->begin(); input != input_set->end(); input++, expected++){
            run_feedforward(this->network, *input);
            backpropagation(this->network, *expected, this->learning_rate);
        }
    }
}

Vector * Model::predict(Vector * input){
    return run_feedforward(this->network, input);
}