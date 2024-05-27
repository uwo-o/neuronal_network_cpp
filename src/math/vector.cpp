#include <iostream>
#include <cstdlib>

#include "math/vector.h"

Vector::Vector(int size) {

    this->size = size;
    this->data = new double[size];

    for (int i = 0; i < size; i++) {
        this->data[i] = ((double) rand() / (RAND_MAX));
    }

}

Vector::Vector(int size, double *data) {
    this->size = size;
    this->data = data;
}

Vector::~Vector() {
    delete[] this->data;
}

int Vector::get_size() {
    return this->size;
}

double Vector::get(int index) {
    return this->data[index];
}

double * Vector::get_data() {
    return this->data;
}

void Vector::add(Vector *vector) {

    if (this->size != vector->size) {
        std::cout << "[ERROR] vectors must have the same size" << std::endl;
        return;
    }

    for (int i = 0; i < this->size; i++) {
        this->data[i] += vector->data[i];
    }
}

double Vector::dot(Vector *vector) {

    if (this->size != vector->size) {
        std::cout << "[ERROR] vectors must have the same size" << std::endl;
        return -1;
    }

    double sum = 0;
    for (int i = 0; i < this->size; i++) {
        sum += this->data[i] * vector->data[i];
    }

    return sum;
}

void Vector::cross(Vector *vector) {

    if (this->size != 3 || vector->size != 3) {
        std::cout << "[ERROR] vectors must have size 3" << std::endl;
        return;
    }

    double *data = new double[3];

    data[0] = this->data[1] * vector->data[2] - this->data[2] * vector->data[1];
    data[1] = this->data[2] * vector->data[0] - this->data[0] * vector->data[2];
    data[2] = this->data[0] * vector->data[1] - this->data[1] * vector->data[0];

    delete[] this->data;
    this->data = data;
}

void Vector::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i] << std::endl;
    }
}

Vector * Vector::copy() {

    double *data = new double[this->size];

    for (int i = 0; i < this->size; i++) {
        data[i] = this->data[i];
    }

    return new Vector(this->size, data);
}

void Vector::apply(double (*function)(double)) {
    for (int i = 0; i < this->size; i++) {
        this->data[i] = function(this->data[i]);
    }
}