#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>

#include "math/matrix.h"
#include "math/vector.h"

class Network {
    private:
        int layers;
        int *neurons;
        double **data;
        Matrix *weights;
        Matrix *biases;
        char ** model_name;

    public:
        Network();
        Network(int layers, int *neurons, double **data);
        ~Network();

        void * get_properties();
        void * get_data();
        Network * copy();
        
        void feedforward();
        void backpropagation();
        void train();
        void predict();
        void test();
        
        void print();
}