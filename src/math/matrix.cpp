#include <cstdlib>

#include "math/matrix.h"

Matrix::Matrix(int rows, int cols, bool random) {

    this->rows = rows;
    this->cols = cols;
    this->data = new double*[rows];

    for (int i = 0; i < rows; i++) {
        this->data[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (random) {
                this->data[i][j] = ((double) rand() / (RAND_MAX));
            } else {
                this->data[i][j] = 0;
            }
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

int Matrix::get_cols(){
    return this->cols;
}

int Matrix::get_rows(){
    return this->rows;
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

Vector * Matrix::mult(Vector * vector) {
    if (this->cols != vector->get_size()) {
        std::cout << "[ERROR] matrix and vector must have the same size" << std::endl;
        return NULL;
    }

    double *data = new double[this->rows];

    for (int i = 0; i < this->rows; i++) {
        data[i] = 0;
        for (int j = 0; j < this->cols; j++) {
            data[i] += this->data[i][j] * vector->get(j);
        }
    }

    return new Vector(this->rows, data);
}

Matrix * Matrix::mult(Matrix * rigth_matrix){
    if (this->cols != rigth_matrix->rows) {
        std::cout << "[ERROR] matrixes must have the same size" << std::endl;
        return NULL;
    }

    double **data = new double*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        data[i] = new double[rigth_matrix->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < rigth_matrix->cols; j++) {
            data[i][j] = 0;
            for (int k = 0; k < this->cols; k++) {
                data[i][j] += this->data[i][k] * rigth_matrix->data[k][j];
            }
        }
    }

    return new Matrix(this->rows, rigth_matrix->cols, data);
}

void Matrix::print() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            std::cout << this->data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Vector * Matrix::get_row(int row) {
    return new Vector(this->cols, this->data[row]);
}

Matrix * Matrix::transpose() {
    double **data = new double*[this->cols];

    for (int i = 0; i < this->cols; i++) {
        data[i] = new double[this->rows];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            data[j][i] = this->data[i][j];
        }
    }
    
    return new Matrix(this->cols, this->rows, data);
}

Matrix * Matrix::identity() {
    double **data = new double*[this->get_rows()];

    for (int i = 0; i < this->get_rows(); i++) {
        data[i] = new double[this->get_cols()];
    }

    for (int i = 0; i < this->get_rows(); i++) {
        for (int j = 0; j < this->get_cols(); j++) {
            if (i == j) {
                data[i][j] = 1;
            } else {
                data[i][j] = 0;
            }
        }
    }

    return new Matrix(this->rows, this->cols, data);
}

Vector * Matrix::to_vector() {
    return new Vector(this->rows * this->cols, (double *) this->data);
}

void Matrix::set(int i, int j, double data){
    this->data[i][j] = data;
}

void Matrix::print_shape() {
    std::cout << "Matrix shape: (" << this->rows << ", " << this->cols << ")" << std::endl;
}
