#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <math.h>
#include <vector>

#include "math/functions.h"

class Layer {
    private:
        int id;
        std::vector<double> *neurons;
        std::vector<double> *input;
        std::vector<std::vector<double> *> *weights;
        std::vector<double> *biases;
        std::vector<double> *Z;
        double (*activation)(double);

    public:
        Layer(int id, int neurons, int input_size);
        ~Layer();

        Layer * copy();

        void print();

        void set_input(std::vector<double> *input);

        int get_id();

        std::vector<double> * get_output();
        std::vector<double> * get_neurons();
        std::vector<double> * get_biases();
        std::vector<std::vector<double>*> * get_weights();
        std::vector<double> * get_Z();

        void set_weights(std::vector<std::vector<double>*> * weights);
        void set_biases(std::vector<double> * biases);
        void set_activation(double (*activation)(double));
        void set_neurons(std::vector<double> * neurons);
        void set_Z(std::vector<double>  * Z);
};

#endif