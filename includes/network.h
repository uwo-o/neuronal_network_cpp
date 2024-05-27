#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>

#include "layer.h"

class Network {
    private:

        int input_size;
        int layers;
        int hlayers_size;
        int output_size;

        double learning_rate;
        char * name;

        double (*activation)(double);

        Layer **network;

    public:
        Network(double learning_rate, int input_size, int hlayers_size, int output_size, double (*activation)(double));
        ~Network();

        void describe();
        void full_describe();

        Layer * get_layer(int id);

        void set_input(Vector *input);
        Vector * get_output();

        void set_name(char *name);
        char * get_name();
};

#endif