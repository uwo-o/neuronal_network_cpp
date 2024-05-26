#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
    private:
        int size;
        double **data;

    public:
        Vector(int size);
        Vector(int size, double **data);
        ~Vector();

        int get_size();
        double ** get_data();
        Vector * copy();
        
        double dot(Vector *vector);
        Vector * cross(Vector *vector);

        void print();
        
        Vector * operator+(Vector *vector);
        Vector * operator-(Vector *vector);
        Vector * operator*(Vector *vector);
        Vector * operator/(Vector *vector);
};

#endif