#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <list>

#include "network.h"
#include "io.h"
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

        void train(Data * data, int epochs);
        std::vector<double> * predict(std::vector<double> * input);
        std::vector<double> * generate_output_by_index(int index);
};

#endif