#include "math/vector.h"
#include "network.h"
#include "layer.h"
#include "math/matrix.h"

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

void feedfordward(Vector * input, Vector * neurons, Layer * current) {

    int input_size = input->get_size();
    Matrix * weights = current->get_weights();
    Vector * bias = current->get_biases();

    Vector * Z = new Vector(input_size);

    for(int i = 0; i<input_size; i++) {
        for( int j = 0; j<weights->get_rows(); j++){
            double b = bias->get(i);
            double a = input->get(i);
            double w = weights->get(i,j);
            Z->insert(i, a*w + b);
        }
    }

    for(int i = 0; i<input_size; i++) {
        neurons->insert(i, sigmoid(Z->get(i)));
    }

    delete Z;
}

void run_feedforward(Network * network, Vector * expected, Vector * input) {
    int size = network->get_layers_size();
    for (int i = 1; i < size; i++) {

        Vector *  prev_output;
        if (i==1) {
            prev_output = input;
        } else {
            prev_output = network->get_layer(i-1)->get_neurons();
        }

        Layer * current = network->get_layer(i);
        feedfordward(prev_output, expected, current);
    }
}