#include "algorithms/backpropagation.h"

void backpropagation(Network * net, std::vector<double> *expected, double learning_rate) {

    int net_size = net->get_layers_size();

    Layer *output_layer = net->get_layer(net_size - 1);
    Layer *prev_layer = net->get_layer(net_size - 2);

    std::vector<double> *output = copy(output_layer->get_neurons());
    std::vector<double> * d_error = copy(expected);

    sustraction(d_error, output);
    sustraction(output, expected);

    double error = (pow(sum_elements(output),2))/2;
    std::cout << "Error: " << error << std::endl;

    std::vector<double> *prev_output = prev_layer->get_neurons();
    std::vector<std::vector<double> *> *output_weights = output_layer->get_weights();
    std::vector<double> *bias = output_layer->get_biases();

    std::vector<double> *deltas = new std::vector<double>(output->size());

    delete output;

    std::vector<double> *Z = output_layer->get_Z();

    // Calculate delta error for output layer
    for (int i = 0; i < Z->size(); i++) {
        for (int j = 0; j < d_error->size(); j++) {
            acumulate(deltas, j, net->get_d_activation()(Z->at(i)) * d_error->at(j));
        }
    }

    delete d_error;

    // Update output weights
    for(int i = 0; i<output_weights->size(); i++) {
        for( int j = 0; j<output_weights->at(0)->size(); j++){

            double w = output_weights->at(i)->at(j);
            double a = prev_output->at(j);
            double delta = deltas->at(i);

            output_weights->at(i)->at(j) = w - (learning_rate * a * delta);
        }
    }
    
    // Update output biases
    for (int i = 0; i < bias->size(); i++) {
        double b = bias->at(i);
        double delta = deltas->at(i);

        bias->at(i) = b - (learning_rate * delta);
    }

    // Backpropagate the error
    for (int i = net_size - 2 ; i >1 ; i--) {

        Layer * layer = net->get_layer(i);
        prev_output = net->get_layer(i-1)->get_neurons();

        Z = net->get_layer(i-1)->get_Z();

        std::vector<std::vector<double> *> * weights = layer->get_weights();
        bias = layer->get_biases();

        std::vector<double> * d_activation = new std::vector<double>(Z->size());

        // Calculate the derivative of the previous activation function
        for (int i = 0; i < Z->size(); i++) {
            d_activation->at(i) = net->get_d_activation()(Z->at(i));
        }

        

        std::vector<double> *n_deltas = new std::vector<double>(Z->size());
        std::vector<double> *aux_deltas = new std::vector<double>(n_deltas->size());

        // Multiplicate d_activation with deltas
        for (int i = 0; i < deltas->size(); i++) {
            for (int j = 0; j < d_activation->size(); j++) {
                acumulate(aux_deltas, j, deltas->at(i) * d_activation->at(j));
            }
        }

        

        // Calculate the deltas for the current layer
        for (int i = 0; i < weights->size(); i++) {
            for( int j = 0; j < weights->at(0)->size(); j++){

                double w = weights->at(i)->at(j);
                double d = aux_deltas->at(j);

                acumulate(n_deltas, j, w * d);
            }
        }

        delete aux_deltas;

        // Update the weights
        for(int i = 0; i<weights->size(); i++) {
            for( int j = 0; j<weights->at(0)->size(); j++){
                double w = weights->at(i)->at(j);
                double delta = n_deltas->at(j);
                double a = prev_output->at(j);

                weights->at(i)->at(j) = w - (learning_rate * a * delta);
            }
        }

        // Update the biases
        for (int i = 0; i < bias->size(); i++) {
            double b = bias->at(i);
            double delta = n_deltas->at(i);

            bias->at(i) = b - (learning_rate * delta);
        }

        delete n_deltas;
        delete d_activation;
    }
}