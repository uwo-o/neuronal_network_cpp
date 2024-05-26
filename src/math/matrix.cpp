#include <cstdlib>

#include "math/matrix.h"

Matrix::Matrix(int rows, int cols) {

    this->rows = rows;
    this->cols = cols;
    this->data = new double*[rows];

    for (int i = 0; i < rows; i++) {
        this->data[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->data[i][j] = ((double) rand() / (RAND_MAX));
        }
    }

}

Matrix::Matrix(int rows, int cols, double **data) {
    this->rows = rows;
    this->cols = cols;
    this->data = data;
}

Matrix::~Matrix() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->data[i];
    }
    delete[] this->data;
}


double Matrix::get(int row, int col) {
    return this->data[row][col];
}

Matrix * Matrix::copy() {
    double **data = new double*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        data[i] = new double[this->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            data[i][j] = this->data[i][j];
        }
    }

    return new Matrix(this->rows, this->cols, data);
}

Vector * Matrix::dot(Vector *vector) {
        
        if (this->cols != vector->get_size()) {
            std::cout << "[ERROR] matrix columns must be equal to vector size" << std::endl;
            return NULL;
        }
    
        double *data = new double[this->rows];
    
        for (int i = 0; i < this->rows; i++) {
            data[i] = 0;
            for (int j = 0; j < this->cols; j++) {
                data[i] += this->data[i][j] * vector[j][0];
            }
        }
    
        return new Vector(this->rows, data);
}

Matrix * Matrix::dot(Matrix *matrix) {
    
    if (this->cols != matrix->rows) {
        std::cout << "[ERROR] matrix columns must be equal to matrix rows" << std::endl;
        return;
    }

    double **data = new double*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        data[i] = new double[matrix->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            data[i][j] = 0;
            for (int k = 0; k < this->cols; k++) {
                data[i][j] += this->data[i][k] * matrix->data[k][j];
            }
        }
    }

    return new Matrix(this->rows, matrix->cols, data);
}

Matrix * Matrix::operator*(Matrix *matrix) {

    double ** data = new double*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        data[i] = new double[matrix->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            data[i][j] = 0;
            for (int k = 0; k < this->cols; k++) {
                data[i][j] += this->data[i][k] * matrix->data[k][j];
            }
        }
    }

    return new Matrix(this->rows, matrix->cols, data);
}

Matrix * Matrix::operator+(Matrix *matrix) {

    if (this->rows != matrix->rows || this->cols != matrix->cols) {
        std::cout << "[ERROR] matrix must have the same size" << std::endl;
        return NULL;
    }

    double **data = new double*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        data[i] = new double[this->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            data[i][j] = this->data[i][j] + matrix->data[i][j];
        }
    }

    return new Matrix(this->rows, this->cols, data);
}