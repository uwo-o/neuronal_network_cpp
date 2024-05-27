#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>

#include "layer.h"

class Network {
    private:

        int input_size;
        int layers;
        int neurons_per_hlayer;
        int output_size;

        double learning_rate;
        char * name;

        double (*activation)(double);

        Layer **network;

    public:
        Network(int layers, double learning_rate, int input_size, int neurons_per_hlayer, int output_size, double (*activation)(double));
        ~Network();

        void print();

        void set_input(Vector *input);
        Vector * get_output();

        void set_name(char *name);
        char * get_name();
};

#endif