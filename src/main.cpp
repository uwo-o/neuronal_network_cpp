#include <iostream>
#include <math.h>

#include "network.h"
#include "algorithms/feedforward.h"
#include "algorithms/backpropagation.h"

int main(int argc, char * argv[]){


    double input_neurons = 3;
    double hidden_neurons = 2;
    double hidden_layers = 2;
    double output_neurons = 1;
    double learning_rate = 0.1;

    Network * network = new Network(input_neurons, hidden_neurons, hidden_layers, output_neurons, learning_rate);
    network->set_name("test");

    Vector * input = new Vector(3, true);

    Vector * output =run_feedforward(network, input);

    Vector * expected = new Vector(1, true);

    backpropagation(network, expected, learning_rate);

    return 0;
}
