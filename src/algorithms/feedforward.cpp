#include "algorithms/feedforward.h"

std::vector<double> * feedfordward(std::vector<double> * input, Layer * current, int size, double (*activation)(double)) {

    int input_size = input->size();
    std::vector<std::vector<double>*> * weights = current->get_weights();

    int l_id = current->get_id();

    std::vector<double> * bias = current->get_biases();

    std::vector<double> * Z = new std::vector<double>(bias->size());

    if (l_id == 1) {
        std::vector<std::vector<double>*>* weights = transpose(current->get_weights());
    }

    int rows = weights->size();
    int cols = weights->at(0)->size();

    std::cout << weights->at(0)->size() << " " << rows << std::endl;

    if (cols != input_size) {
        throw "Input vector size does not match the weights size";
    }

    for(int i = 0; i<cols; i++) {
        for( int j = 0; j<rows; j++){
            std::cout << i << " " << j << " " << weights->at(j)->at(i) << std::endl;
            double a = input->at(i);
            double b = bias->at(j);
            double w = weights->at(j)->at(i);
            acumulate(Z, j, a*w + b);
        }
    }

    if (l_id == 1) {
        for (int i = 0; i < weights->size() -1 ; i++) {
            delete weights->at(i);
        }
        delete weights;
    }

    std::vector<double> * Z_c = copy(Z);

    current->set_Z(Z_c);

    for (int i = 0; i < Z->size() -1 ; i++) {
        Z->at(i) = activation(Z->at(i));
    }

    current->set_neurons(Z);

    return Z;
}

std::vector<double> * run_feedforward(Network * network, std::vector<double> * input) {
    int size = network->get_layers_size();

    network->get_layer(0)->set_neurons(input);

    std::vector<double> *  prev_output = input;
    try {
        for (int i = 1; i < size; i++) {
            Layer * current = network->get_layer(i);
            prev_output = feedfordward(prev_output, current, size, network->get_activation());
        }
    }
    catch (char const * err){
        std::cout << "[ERROR]" << err << " in feedfordward algorithm" << std::endl;
    }

    return prev_output;
}