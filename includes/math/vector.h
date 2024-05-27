#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
    private:
        int size;
        double *data;

    public:
        Vector(int size);
        Vector(int size, double *data);
        ~Vector();

        int get_size();
        double get(int index);
        double * get_data();
        Vector * copy();
        
        void add(Vector *vector);
        double dot(Vector *vector);
        void cross(Vector *vector);
        void apply(double (*function)(double));
        void set(int index, double value);

        void print();
};

#endif