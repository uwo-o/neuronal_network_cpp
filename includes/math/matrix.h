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
        
        Vector * dot(Vector *vector);
        Matrix * dot(Matrix *matrix);
        Matrix * sum(Matrix *matrix);
        Matrix * determinant();
        Matrix * transpose();
        Matrix * inverse();
        Matrix * scalar(double scalar);

        void print();
        
        Matrix * operator+(Matrix *matrix);
        Matrix * operator-(Matrix *matrix);
        Matrix * operator*(Matrix *matrix);
        Matrix * operator/(Matrix *matrix);
};

#endif