#include "math/vector.h"
#include "network.h"
#include "layer.h"
#include "math/matrix.h"

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

Vector * feedfordward(Vector * input, Layer * current) {

    int input_size = input->get_size();
    Matrix * weights = current->get_weights();

    int rows = weights->get_rows();

    if (weights->get_rows() == 1) {
        weights = weights->transpose();
    }

    Vector * bias = current->get_biases();

    Vector * Z = new Vector(bias->get_size());

    for(int i = 0; i<input_size; i++) {
        for( int j = 0; j<rows; j++){
            double b = bias->get(j);
            double a = input->get(j);
            double w = weights->get(i,j);
            Z->insert(j, a*w + b);
        }
    }

    Vector * out = new Vector(bias->get_size());
    delete Z;

    return out;
}

Vector * run_feedforward(Network * network, Vector * input) {
    int size = network->get_layers_size();

     Vector *  prev_output = input;

    for (int i = 1; i < size; i++) {
        Layer * current = network->get_layer(i);
        prev_output = feedfordward(prev_output, current);
    }

    return prev_output;
}