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
        double (*activation)(double);

    public:
        Layer(int id, int neurons, int input_size);
        ~Layer();

        Layer * copy();

        void print();

        void set_input(Vector *input);
        Vector * get_output();
        Vector * get_neurons();
        Vector * get_biases();
        Matrix * get_weights();
};

#endif