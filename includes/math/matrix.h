#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "math/vector.h"

class Matrix {
    private:
        int rows;
        int cols;
        double **data;

    public:
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, double **data);
        ~Matrix();

        double get(int row, int col);
        Matrix * copy();
        
        Matrix * add(Matrix *matrix);
        Vector * mult(Vector *vector);
        Matrix * mult(Matrix *rigth_matrix);
        Matrix * determinant();
        Matrix * transpose();
        Matrix * inverse();
        Matrix * scalar(double scalar);

        void print();
};

#endif