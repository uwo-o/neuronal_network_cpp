#ifndef LAYER_H
#define LAYER_H

#include <iostream>

#include "math/matrix.h"
#include "math/vector.h"

class Layer {
    private:
        int id;
        Vector *neurons;
        Vector *input;
        Matrix *weights;
        Vector *biases;
        Vector *Z;
        double (*activation)(double);

    public:
        Layer(int id, int neurons, int input_size);
        ~Layer();

        Layer * copy();

        void print();

        void set_input(Vector *input);

        int get_id();

        Vector * get_output();
        Vector * get_neurons();
        Vector * get_biases();
        Matrix * get_weights();
        Vector * get_Z();

        void set_weights(Matrix * weights);
        void set_biases(Vector * biases);
        void set_activation(double (*activation)(double));
        void set_neurons(Vector * neurons);
        void set_Z(Vector * Z);
};

#endif