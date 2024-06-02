#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <list>

#include "network.h"
#include "algorithms/feedforward.h"
#include "algorithms/backpropagation.h"

class Model {
    private:
        Network * network;
        double learning_rate;

    public:
        Model(std::string name, double input_neurons, double hidden_neurons, double hidden_layers, double output_neurons, double learning_rate);
        ~Model();

        void set_activation(double (*activation)(double));
        void set_d_activation(double (*d_activation)(double));

        void train(std::list<Vector *> * input_set, std::list<Vector *> * expected_set, int epochs);
        Vector * predict(Vector * input);
};

#endif