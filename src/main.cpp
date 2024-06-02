#include <iostream>
#include <math.h>

#include "math/activation.h"
#include "model.h"

int main(int argc, char * argv[]){


    double input_neurons = 1;
    double hidden_neurons = 3;
    double hidden_layers = 3;
    double output_neurons = 1;
    double learning_rate = 0.01;

    Model * model = new Model("test", input_neurons, hidden_neurons, hidden_layers, output_neurons, learning_rate);

    return 0;
}
