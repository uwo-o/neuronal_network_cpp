#include "math/vector.h"

Vector::Vector(int size) {

    this->size = size;
    this->data = new double*[size];

    for (int i = 0; i < size; i++) {
        this->data[i] = new double[1];
    }

}

Vector::Vector(int size, double **data) {
    this->size = size;
    this->data = data;
}

Vector::~Vector() {
    for (int i = 0; i < this->size; i++) {
        delete[] this->data[i];
    }
    delete[] this->data;
}

int Vector::get_size() {
    return this->size;
}

double ** Vector::get_data() {
    return this->data;
}

double Vector::dot(Vector *vector) {

    if (this->size != vector->size) {
        std::cout << "Error: vectors must have the same size" << std::endl;
        return -1;
    }

    double sum = 0;
    for (int i = 0; i < this->size; i++) {
        sum += this->data[i][0] * vector->data[i][0];
    }

    return sum;
}

Vector * Vector::cross(Vector *vector) {

    if (this->size != 3 || vector->size != 3) {
        std::cout << "Error: vectors must have size 3" << std::endl;
        return NULL;
    }

    double **data = new double*[3];

    data[0] = new double[1];
    data[1] = new double[1];
    data[2] = new double[1];

    data[0][0] = this->data[1][0] * vector->data[2][0] - this->data[2][0] * vector->data[1][0];
    data[1][0] = this->data[2][0] * vector->data[0][0] - this->data[0][0] * vector->data[2][0];
    data[2][0] = this->data[0][0] * vector->data[1][0] - this->data[1][0] * vector->data[0][0];

    return new Vector(3, data);
}

void Vector::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i][0] << std::endl;
    }
}

Vector * Vector::copy() {

    double **data = new double*[this->size];

    for (int i = 0; i < this->size; i++) {
        data[i] = new double[1];
        data[i][0] = this->data[i][0];
    }

    return new Vector(this->size, data);
}

Vector * Vector::operator+(Vector *vector) {

    if (this->size != vector->size) {
        std::cout << "Error: vectors must have the same size" << std::endl;
        return NULL;
    }

    double **data = new double*[this->size];

    for (int i = 0; i < this->size; i++) {
        data[i] = new double[1];
        data[i][0] = this->data[i][0] + vector->data[i][0];
    }

    return new Vector(this->size, data);
}

Vector * Vector::operator-(Vector *vector) {

    if (this->size != vector->size) {
        std::cout << "Error: vectors must have the same size" << std::endl;
        return NULL;
    }

    double **data = new double*[this->size];
    for (int i = 0; i < this->size; i++) {
        data[i] = new double[1];
        data[i][0] = this->data[i][0] - vector->data[i][0];
    }

    return new Vector(this->size, data);
}

Vector * Vector::operator*(int scalar) {

    double **data = new double*[this->size];

    for (int i = 0; i < this->size; i++) {
        data[i] = new double[1];
        data[i][0] = this->data[i][0] * scalar;
    }

    return new Vector(this->size, data);
}

Vector * Vector::operator/(int scalar) {

    if (scalar ==0 ) {
        std::cout << "Error: division by zero" << std::endl;
        return NULL;
    }

    double **data = new double*[this->size];

    for (int i = 0; i < this->size; i++) {
        data[i] = new double[1];
        data[i][0] = this->data[i][0] / scalar;
    }

    return new Vector(this->size, data);
}