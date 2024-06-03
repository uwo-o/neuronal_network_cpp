#include "algorithms/backpropagation.h"

void backpropagation(Network * net, double learning_rate, std::vector<double> *deltas, int current_layer) {
    
    if (current_layer == 1) {
        return;
    }

    Layer *current = net->get_layer(current_layer);
    Layer *previous = net->get_layer(current_layer - 1);


    std::vector<double> *Z = previous->get_Z();
    std::vector<double> *previous_neurons = previous->get_neurons();


    std::vector<std::vector<double> *> *weights = current->get_weights();
    std::vector<double> *bias = current->get_biases();


    std::vector<double> *deltas_previous = new std::vector<double>(previous_neurons->size());
    std::vector<double> *derivade_previous = new std::vector<double>(previous_neurons->size());

    if (current_layer == net->get_layers_size() - 1) {
        

        for(int i = 0; i<weights->size(); i++) {
            for( int j = 0; j<weights->at(0)->size(); j++){

                double w = weights->at(i)->at(j);
                double a = previous_neurons->at(i); 
                double delta = deltas->at(i);

                weights->at(i)->at(j) = w - (learning_rate * a * delta);
            }
        }

        for(int i = 0; i<bias->size(); i++) {
            double b = bias->at(i);
            double delta = deltas->at(i);
            bias->at(i) = b - (learning_rate * delta);;
        }

        backpropagation(net, learning_rate, deltas_previous, current_layer - 1);
        return;
    }

    for(int i = 0; i<weights->size(); i++) {
        for(int j = 0; j<weights->at(0)->size(); j++) {
            acumulate(derivade_previous, j, weights->at(i)->at(j) * deltas->at(i));
        }
    }

    for(int i = 0; i<Z->size(); i++) {
        deltas_previous->at(i) = derivade_previous->at(i) * net->get_d_activation()(Z->at(i));
    }

    for(int i = 0; i<weights->size(); i++) {
        for( int j = 0; j<weights->at(0)->size(); j++){

            double w = weights->at(i)->at(j);
            double a = previous_neurons->at(i); 
            double delta = deltas_previous->at(i);

            weights->at(i)->at(j) = w - (learning_rate * a * delta);
        }
    }

    for(int i = 0; i<bias->size(); i++) {
        double b = bias->at(i);
        double delta = deltas_previous->at(i);

        bias->at(i) = b - (learning_rate * delta);
    }
    
    backpropagation(net, learning_rate, deltas_previous, current_layer - 1);

}

void run_backpropagation(Network * net, std::vector<double> *expected, double learning_rate) {

    int net_size = net->get_layers_size();
    Layer *output_layer = net->get_layer(net_size - 1);

    std::vector<double> *output = copy(output_layer->get_neurons());

    std::vector<double> * d_error = copy(expected);

    sustraction(d_error, output);
    sustraction(output, expected);

    double error = (pow(sum_elements(output),2))/output->size();
    std::cout << "Error: " << error << std::endl;

    std::vector<double> *deltas = new std::vector<double>(output->size());

    delete output;

    std::vector<double> *Z = output_layer->get_Z();

    // Calculate delta error for output layer
    for (int i = 0; i < deltas->size(); i++) {
        deltas->at(i) = d_error->at(i) * net->get_d_activation()(Z->at(i));
    }

    delete d_error;

    backpropagation(net, learning_rate, deltas, net_size - 1);
}