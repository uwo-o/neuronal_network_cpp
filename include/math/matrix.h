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
        Matrix(int rows, int cols, bool random = false);
        Matrix(int rows, int cols, double **data);
        ~Matrix();

        double get(int row, int col);
        Vector * get_row(int row);
        int get_cols();
        int get_rows();
        Matrix * copy();
        
        Matrix * add(Matrix *matrix);
        Vector * mult(Vector *vector);
        Matrix * mult(Matrix *rigth_matrix);
        Matrix * determinant();
        Matrix * transpose();
        Matrix * inverse();
        Matrix * scalar(double scalar);
        Matrix * identity();
        Vector * to_vector();

        void print();
};

#endif