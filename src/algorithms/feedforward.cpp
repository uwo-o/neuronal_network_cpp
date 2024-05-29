#include "math/vector.h"
#include "network.h"
#include "layer.h"
#include "math/matrix.h"

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

Vector * feedfordward(Vector * input, Vector * expected, Layer * current) {

    int input_size = input->get_size();
    Matrix * weights = current->get_weights();
    Vector * bias = current->get_biases();

    Vector * Z = new Vector(input_size);
    Vector * A = new Vector(input_size);

    for(int i = 0; i<input_size; i++) {
        for( int j = 0; j<weights->get_rows(); j++){
            double b = bias->get(i);
            double a = input->get(i);
            double w = weights->get(i,j);
            Z->insert(i, a*w + b);
        }
    }

    for(int i = 0; i<input_size; i++) {
        A->insert(i, sigmoid(Z->get(i)));
    }

    return A;
}