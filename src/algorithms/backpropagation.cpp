#include "algorithms/backpropagation.h"

void backpropagation(Network * net, double learning_rate, std::vector<double> *deltas, int current_layer) {

    if (current_layer == 0) {
        return;
    }

    Layer * current_l = net->get_layer(current_layer);
    Layer * previous_l = net->get_layer(current_layer - 1);

    std::vector<std::vector<double> *> * weights = current_l->get_weights();
    std::vector<double> * biases = current_l->get_biases();
    std::vector<double> * prev_neurons = previous_l->get_neurons();

    for (int i = 0; i < weights->size(); i++) {
        for (int j = 0; j < weights->at(i)->size(); j++) {
            weights->at(i)->at(j) -= learning_rate * deltas->at(i) * prev_neurons->at(j);
        }
    }

    for (int i = 0; i < biases->size(); i++) {
        biases->at(i) -= learning_rate * deltas->at(i);
    }

    std::vector<std::vector<double>  *> * weights_t = transpose(weights);
    deltas = vec_mult(weights_t, deltas);

    deltas = vec_mult(deltas, vec_apply(prev_neurons, net->get_d_activation()));

    backpropagation(net, learning_rate, deltas, current_layer - 1);
}

void run_backpropagation(Network * net, std::vector<double> *expected, double learning_rate) {

    int num_layers = net->get_layers_size();
    Layer * output_layer = net->get_layer(num_layers- 1);

    std::vector<double> * output = output_layer->get_neurons();

    std::vector<double>  * error = vec_sub(expected, output);
    double ponderated_error = dot(error, error)/output->size();
    std::cout << "Error: " << ponderated_error << std::endl;

    std::vector<double> * deltas = new std::vector<double>(output->size());

    deltas = vec_scalar(vec_sub(output, expected), -1);

    deltas = vec_mult(deltas, vec_apply(output, net->get_d_activation()));

    backpropagation(net, learning_rate, deltas, num_layers - 1);
}