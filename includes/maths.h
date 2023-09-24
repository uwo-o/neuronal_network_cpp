#ifndef MATHS_H
#define MATHS_H

class Matrix {
    private:
        int rows;
        int cols;
        double **data;

    public:
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, double **data);
        ~Matrix();

        void * get_properties();
        void * get_data();
        void * get_data(int row, int col);
        Matrix * copy();
        
        void dot(Matrix *matrix);
        void sum(Matrix *matrix);
        double determinant();
        void transpose();
        void inverse();
        void scalar(double scalar);
}

#endif