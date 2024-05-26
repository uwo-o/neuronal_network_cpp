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

        void * get_properties();
        void * get_data();
        void * get_data(int row, int col);
        Vector * copy();
        
        void dot(Vector *vector);
        void cross(Vector *vector);

        void print();
        
        Vector * operator+(Vector *vector);
        Vector * operator-(Vector *vector);
        Vector * operator*(Vector *vector);
        Vector * operator/(Vector *vector);
}

#endif