#include "algorithms/backpropagation.h"

void backpropagation(Network * net, Vector *expected, double learning_rate) {

    int net_size = net->get_layers_size();

    Layer *output_layer = net->get_layer(net_size - 1);
    Layer *prev_layer = net->get_layer(net_size - 2);

    Vector *output = output_layer->get_neurons()->copy();

    output->subtraction(expected);

    double error = (pow(output->sum_elements(),2))/2;
    std::cout << "Error: " << error << std::endl;

    Vector * d_error = expected->copy();
    d_error->subtraction(output);

    Vector *prev_output = prev_layer->get_neurons();
    Matrix *output_weights = output_layer->get_weights();
    Vector *bias = output_layer->get_biases();

    Vector *deltas = new Vector(output->get_size());

    delete output;

    Vector *Z = output_layer->get_Z();

    // Calculate delta error for output layer
    for (int i = 0; i < Z->get_size(); i++) {
        for (int j = 0; j < d_error->get_size(); j++) {
            deltas->accumulate(j, net->get_d_activation()(Z->get(i)) * d_error->get(j));
        }
    }

    delete d_error;
    
    // Update output weights
    for(int i = 0; i<output_weights->get_cols(); i++) {
        for( int j = 0; j<output_weights->get_rows(); j++){

            double w = output_weights->get(j,i);
            double a = prev_output->get(i);
            double delta = deltas->get(j);

            output_weights->set(j, i, w - learning_rate * a * delta);
        }
    }
    
    // Update output biases
    for (int i = 0; i < bias->get_size(); i++) {
        double b = bias->get(i);
        double delta = deltas->get(i);

        bias->set(i, b - learning_rate * delta);
    }

    // Backpropagate the error
    for (int i = net_size - 2 ; i >1 ; i--) {

        Layer * layer = net->get_layer(i);
        prev_output = net->get_layer(i-1)->get_neurons();

        Z = net->get_layer(i-1)->get_Z();

        Matrix * weights = layer->get_weights();
        bias = layer->get_biases();

        Vector * d_activation = new Vector(Z->get_size());

        // Calculate the derivative of the previous activation function
        for (int i = 0; i < Z->get_size(); i++) {
            d_activation->set(i, net->get_d_activation()(Z->get(i)));
        }

        Vector *n_deltas = new Vector(Z->get_size());
        Vector *aux_deltas = new Vector(n_deltas->get_size());

        // Multiplicate d_activation with deltas
        for (int i = 0; i < deltas->get_size(); i++) {
            for (int j = 0; j < d_activation->get_size(); j++) {
                aux_deltas->accumulate(j, deltas->get(i) * d_activation->get(j));
            }
        }

        // Calculate the deltas for the current layer
        for (int i = 0; i < weights->get_cols(); i++) {
            for( int j = 0; j < weights->get_rows(); j++){

                double w = weights->get(j,i);
                double d = aux_deltas->get(i);

                n_deltas->accumulate(j, w * d);
            }
        }

        delete aux_deltas;

        // Update the weights
        for(int i = 0; i<weights->get_cols(); i++) {
            for( int j = 0; j<weights->get_rows(); j++){
                double w = weights->get(j,i);
                double delta = n_deltas->get(i);
                double a = prev_output->get(j);

                weights->set(j, i, w - learning_rate * a * delta);
            }
        }

        // Update the biases
        for (int i = 0; i < bias->get_size(); i++) {
            double b = bias->get(i);
            double delta = n_deltas->get(i);

            bias->set(i, b - learning_rate * delta);
        }

        delete n_deltas;
        delete d_activation;
    }
}