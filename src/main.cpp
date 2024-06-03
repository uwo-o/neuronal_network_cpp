#include <iostream>
#include <math.h>

#include "math/activation.h"
#include "model.h"
#include "io.h"

int main(int argc, char * argv[]){


    double input_neurons = 784;
    double hidden_neurons = 16;
    double hidden_layers = 1;
    double output_neurons = 10;
    double learning_rate = 0.01;

    Data * data = read_csv("/home/uwo/Projects/neuronal_network_cpp/data/MNIST/mnist_train.csv");

    normalize_data_zero_to_one(data);

    data->outputs = new std::vector<std::vector<double> *>();

    Model * model = new Model("MNIST", input_neurons, hidden_neurons, hidden_layers, output_neurons, learning_rate);

    for(int i = 0; i < data->expected->size(); i++){
        data->outputs->push_back(model->generate_output_by_index((int) (data->expected->at(i))));
    }

    model->set_activation(sigmoid);
    model->set_d_activation(d_sigmoid);
    model->train(data, 10);


    return 0;
}
