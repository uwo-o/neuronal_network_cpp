#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <math.h>

#include "layer.h"

class Network {
    private:

        int input_size;
        int layers;
        int hlayers_size;
        int output_size;
        double learning_rate;
        std::string name;
        Layer **network;

        double (Network::*activation)(double);

    public:
        Network(int input_size, int hlayers_size, int output_size, double learning_rate);
        ~Network();

        void describe();
        void fdescribe();

        Layer * get_layer(int id);

        void set_input(Vector *input);

        Vector * get_output();

        void set_name(std::string name);
        std::string get_name();

        int get_layers_size();

        void set_activation(double (*activation)(double));
};

#endif