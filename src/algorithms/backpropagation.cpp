#include "algorithms/backpropagation.h"

void backpropagation(int n_layers, int *neurons, Layer ** layers, Vector *errors, double learning_rate, int epochs){

    Gradient * gradient = new Gradient(dsigmoide);

    for(int i = 0; i < epochs; i++){
        for(int j = n_layers - 1; j >= 0; j--){
            Layer * current = layers[j];
            Layer * prev = layers[j - 1];
            Vector ** gradients = gradient->calculate(current->get_neurons(), prev->get_neurons(), errors);

            for (int k = 0; k < current->get_neurons()->get_size(); k++){
                Vector * gradient = gradients[k];
                double dc_dw = gradient->get(0);
                double dc_db = gradient->get(1);

                current->get_weights()->get_row(j)->set(k, current->get_weights()->get_row(j)->get(k) - learning_rate * dc_dw);
                current->get_biases()->set(k, current->get_biases()->get(k) - learning_rate * dc_db);

            }
    }   }
}