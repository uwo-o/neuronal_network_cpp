#include "algorithms/backpropagation.h"

void backpropagation(Network * net, Vector *expected, double learning_rate) {

    int net_size = net->get_layers_size();
    Layer *output_layer = net->get_layer(net_size - 1);
    Vector *output = output_layer->get_neurons()->copy();
    output->subtraction(expected);
    double error = output->sum_elements();

    Vector *prev_output = net->get_layer(net_size - 2)->get_neurons();
    Matrix *output_weights = output_layer->get_weights();
    Vector *bias = output_layer->get_biases();

    Vector * Z = new Vector(prev_output->get_size());

    output_weights = output_weights->transpose();

    for(int i = 0; i<output_weights->get_cols(); i++) {
        for( int j = 0; j<output_weights->get_rows(); j++){
            double b = bias->get(i);
            double a = prev_output->get(j);
            double w = output_weights->get(j,i);

            Z->accumulate(j, a*w + b);
        }
    }

    Vector *deltas = new Vector(output->get_size());
    
    for (int i = 0; i < Z->get_size(); i++) {
        for (int j = 0; j < output->get_size(); j++) {
            deltas->accumulate(j, d_sigmoid(Z->get(i)) * d_sigmoid(Z->get(i)) * output->get(j));
        }
    }
    
    for(int i = 0; i<output_weights->get_cols(); i++) {
        for( int j = 0; j<output_weights->get_rows(); j++){
            double w = output_weights->get(j,i);
            double a = prev_output->get(j);
            double delta = deltas->get(i);

            output_weights->set(j, i, w - learning_rate * a * delta);
        }
    }

    // Update original output weights
    for(int i = 0; i<output_weights->get_cols(); i++) {
        for( int j = 0; j<output_weights->get_rows(); j++){
            output_layer->get_weights()->set(i, j, output_weights->get(j,i));
        }
    }
    
    bias->print();
    for (int i = 0; i < bias->get_size(); i++) {
        double b = bias->get(i);
        double delta = deltas->get(i);

        bias->set(i, b - learning_rate * delta);
    }

    // works utilz here

    for (int i = net_size -2 ; i >0 ; i--) {
        Layer * layer = net->get_layer(i);
        Vector * d_activation = new Vector(prev_output->get_size());
        prev_output = net->get_layer(i-1)->get_neurons();
        Matrix * weights = layer->get_weights();

        for (int i = 0; i < weights->get_cols(); i++) {
            for( int j = 0; j < weights->get_rows(); j++){
                double b = bias->get(j);
                double a = prev_output->get(j);
                double w = output_weights->get(i,j);

                Z->accumulate(j, a*w + b);
            }
        }

        for (int i = 0; i < Z->get_size(); i++) {
            d_activation->set(i, d_sigmoid(Z->get(i)) * d_sigmoid(Z->get(i)) * output->get(i));
        }

        Vector *n_deltas = new Vector(Z->get_size());

        for (int i = 0; i < weights->get_cols(); i++) {
            for( int j = 0; j < weights->get_rows(); j++){
                double w = output_weights->get(i,j);
                double d = deltas->get(i);
                double z = d_activation->get(j);
                n_deltas->accumulate(j, w * d * z);
            }
        }


        for(int i = 0; i<weights->get_cols(); i++) {
            for( int j = 0; j<weights->get_rows(); j++){
                double w = weights->get(i,j);
                double a = prev_output->get(j);
                double delta = n_deltas->get(i);

                weights->set(i, j, w - learning_rate * a * delta);
            }
        }

        for (int i = 0; i < bias->get_size(); i++) {
            double b = bias->get(i);
            double delta = n_deltas->get(i);

            bias->set(i, b - learning_rate * delta);
        }

        for(int i = 0; i<output_weights->get_cols(); i++) {
            for( int j = 0; j<output_weights->get_rows(); j++){
                weights->set(i, j, output_weights->get(i,j));
            }
        }

        prev_output = layer->get_neurons();
    }
}