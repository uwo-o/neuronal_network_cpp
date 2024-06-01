#include <iostream>
#include <cstdlib>

#include "math/vector.h"

Vector::Vector(int size, bool random) {

    this->size = size;
    this->data = new double[size];

    for (int i = 0; i < size; i++) {
        if (random) {
            this->data[i] = ((double) rand() / (RAND_MAX));
        } else {
            this->data[i] = 0;
        }
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

    if (this->size != vector->size) throw "Vectors must have the same size for addition";

    for (int i = 0; i < this->size; i++) {
        this->data[i] += vector->data[i];
    }

}

void Vector::subtraction(Vector *vector) {

    if (this->size != vector->size) throw "Vectors must have the same size for subtraction";
    

    for (int i = 0; i < this->size; i++) {
        this->data[i] -= vector->data[i];
    }
    
}

double Vector::dot(Vector *vector) {

    if (this->size != vector->size) throw "Vectors must have the same size for dot product";
    

    double sum = 0;
    for (int i = 0; i < this->size; i++) {
        sum += this->data[i] * vector->data[i];
    }

    return sum;
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

void Vector::set(int index, double value) {
    if (index < 0 || index >= this->size) throw "Vectors must have the same size for setting value";
    
    this->data[index] = value;
}

void Vector::accumulate(int index, double value) {
    if (index < 0 || index >= this->size) throw "Vectors must have the same size for setting value";
    
    this->data[index] += value;
}

void Vector::expand(Vector *vector) {
    double *data = new double[this->size + vector->size];

    for (int i = 0; i < this->size; i++) {
        data[i] = this->data[i];
    }

    for (int i = 0; i < vector->size; i++) {
        data[this->size + i] = vector->data[i];
    }

    delete[] this->data;
    this->data = data;
    this->size += vector->size;
}
void Vector::apply(double (*function)(double)) {
    for (int i = 0; i < this->size; i++) {
        this->data[i] = function(this->data[i]);
    }
}

double Vector::sum_elements() {
    double sum = 0;
    for (int i = 0; i < this->size; i++) {
        sum += this->data[i];
    }
    return sum;
}

void Vector::clear() {
    for (int i = 0; i < this->size; i++) {
        this->data[i] = 0;
    }
}