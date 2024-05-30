#include "math/vector.h"
#include "network.h"
#include "layer.h"
#include "math/matrix.h"

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

Vector * feedfordward(Vector * input, Layer * current, int size) {

    int input_size = input->get_size();
    Matrix * weights = current->get_weights();

    int rows = weights->get_rows();
    int cols = weights->get_cols();

    if (cols != input_size) {
        throw "Input vector size does not match the weights size";
    }

    if (current->get_id() == size - 1 ) {
        weights = weights->transpose();
    }

    Vector * bias = current->get_biases();

    Vector * Z = new Vector(bias->get_size());

    for(int i = 0; i<cols; i++) {
        for( int j = 0; j<rows; j++){
            double b = bias->get(j);
            double a = input->get(j);
            double w = weights->get(i,j);
            Z->insert(j, a*w + b);
        }
    }


    Vector * out = new Vector(bias->get_size());
    delete Z;

    current->set_neurons(out);

    return out;
}

Vector * run_feedforward(Network * network, Vector * input) {
    int size = network->get_layers_size();

     Vector *  prev_output = input;
    try {
        for (int i = 1; i < size; i++) {
            Layer * current = network->get_layer(i);
            prev_output = feedfordward(prev_output, current, size);
        }
    }
    catch (char const * err){
        std::cout << "[ERROR]" << err << " in feedfordward algorithm" << std::endl;
    }

    return prev_output;
}