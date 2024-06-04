#include "algorithms/backpropagation.h"

void backpropagation(Network * net, double learning_rate, std::vector<double> *deltas, int current_layer) {

}

void run_backpropagation(Network * net, std::vector<double> *expected, double learning_rate) {

    int num_layers = net->get_layers_size();
    Layer * output_layer = net->get_layer(num_layers- 1);

    std::vector<double> * output = output_layer->get_neurons();

    std::vector<double>  * error = vec_sub(expected, output);
    double ponderated_error = dot(error, error)/2;

    std::vector<double> * deltas = new std::vector<double>(output->size());

    deltas = vec_scalar(vec_sub(output, expected), -1);
    deltas = vec_mult(deltas, vec_apply(output, net->get_d_activation()));

    backpropagation(net, learning_rate, deltas, num_layers - 1);
}