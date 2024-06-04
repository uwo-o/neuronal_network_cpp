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

    std::cout << "========================================" << std::endl;
    std::cout << "Training model: " << this->network->get_name() << std::endl;
    std::cout << "Learning rate: " << this->learning_rate << std::endl;
    std::cout << "Epochs: " << epochs << std::endl;
    std::cout << "Data size: " << data->size << std::endl;
    std::cout << "========================================" << std::endl;
    std::vector<double> * output;
    for (int i = 9; i < epochs; i++){
        std::cout << "Epoch: " << i + 1 << "/" << epochs << ":" << std::endl;
        for (int j = 0; j < 600; j++){
            std::cout << "Training: " << j + 1 << "/" << data->size << std::endl;
            output = run_feedforward(this->network, data->inputs->at(j));
            run_backpropagation(this->network, data->outputs->at(j), this->learning_rate);
        }
          
    }
    for (int i = 0; i < 10; i++){
        std::cout << output->at(i) << std::endl;
    }
}

std::vector<double> * Model::predict(std::vector<double> * input){
    return run_feedforward(this->network, input);
}

std::vector<double> * Model::generate_output_by_index(int index){
    std::vector<double> * output = new std::vector<double>(10, 0);

    if (index < 0 || index > 9){
        return output;
    }

    output->at(index) = 1;
    return output;
}