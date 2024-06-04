#include "math/functions.h"

#include <iostream>

void acumulate(std::vector<double> * v, int pos, int value){
    v->at(pos) += value;
}

std::vector<double> * copy(std::vector<double> * v){
    std::vector<double> * copy = new std::vector<double>(v->size());
    for (int i = 0; i < v->size(); i++) {
        copy->at(i) = v->at(i);
    }
    return copy;
}

void sustraction(std::vector<double> * vec_1, std::vector<double> * vec_2){
    for (int i = 0; i < vec_1->size(); i++) {
        vec_1->at(i) -= vec_2->at(i);
    }
}

double sum_elements(std::vector<double> * vec){
    double sum = 0;
    for (int i = 0; i < vec->size(); i++) {
        sum += vec->at(i);
    }
    return sum;
}

std::vector<std::vector<double>*> * transpose(std::vector<std::vector<double>*> * matrix){
    std::vector<std::vector<double>*> * transposed = new std::vector<std::vector<double>*>(matrix->at(0)->size());

    Garbage::add((void *)transposed);

    for (int i = 0; i < matrix->at(0)->size(); i++) {
        transposed->at(i) = new std::vector<double>(matrix->size());
        Garbage::add((void *)transposed->at(i));
    }

    for (int i = 0; i < matrix->size(); i++) {
        for (int j = 0; j < matrix->at(i)->size(); j++)
        {
            transposed->at(j)->at(i) = matrix->at(i)->at(j);
        }
    }
    return transposed;
}

void randomize_vector(std::vector<double> * vec){
    for (int i = 0; i < vec->size(); i++) {
        vec->at(i) = (double)rand() / RAND_MAX;
    }
}
void randomize_matrix(std::vector<std::vector<double>*> * matrix){
    for (int i = 0; i < matrix->size(); i++) {
        randomize_vector(matrix->at(i));
    }
}

double dot(std::vector<double> * vec_1, std::vector<double> * vec_2){
    double result = 0;
    for (int i = 0; i < vec_1->size(); i++) {
        result += vec_1->at(i) * vec_2->at(i);
    }
    return result;
}


std::vector<double> * vec_sub(std::vector<double> * vec_1, std::vector<double> * vec_2){
    std::vector<double> * result = new std::vector<double>(vec_1->size());

    Garbage::add((void *)result);

    for (int i = 0; i < vec_1->size(); i++) {
        result->at(i) = vec_1->at(i) - vec_2->at(i);
    }
    return result;
}

std::vector<double> * vec_scalar(std::vector<double> * vec_1, double scalar){
    std::vector<double> * result = new std::vector<double>(vec_1->size());

    Garbage::add((void *)result);

    for (int i = 0; i < vec_1->size(); i++) {
        result->at(i) = vec_1->at(i) * scalar;
    }
    return result;
}

std::vector<double> * vec_apply(std::vector<double> * vec_1, double (*f)(double)){
    std::vector<double> * result = new std::vector<double>(vec_1->size());

    Garbage::add((void *)result);

    for (int i = 0; i < vec_1->size(); i++) {
        result->at(i) = f(vec_1->at(i));
    }
    return result;
}

std::vector<double> * vec_mult(std::vector<double> * vec_1, std::vector<double> * vec_2){
    std::vector<double> * result = new std::vector<double>(vec_1->size());

    Garbage::add((void *)result);

    for (int i = 0; i < vec_1->size(); i++) {
        for (int j = 0; j < vec_2->size(); j++) {
            result->at(i) += vec_1->at(i) * vec_2->at(j);
        }
    }
    return result;
}

std::vector<double> * vec_mult(std::vector<std::vector<double>  *> * matrix, std::vector<double> * vec){
    std::vector<double> * result = new std::vector<double>(matrix->size());

    Garbage::add((void *)result);

    for (int i = 0; i < matrix->size(); i++) {
        for (int j = 0; j < matrix->at(i)->size(); j++) {
            result->at(i) += matrix->at(i)->at(j) * vec->at(j);
        }
    }
    return result;
}

std::vector<double> * vec_cross(std::vector<double> * vec_1, std::vector<double> * vec_2){
    std::vector<double> * result = new std::vector<double>(vec_1->size());

    Garbage::add((void *)result);

    result->at(0) = vec_1->at(1) * vec_2->at(2) - vec_1->at(2) * vec_2->at(1);
    result->at(1) = vec_1->at(2) * vec_2->at(0) - vec_1->at(0) * vec_2->at(2);
    result->at(2) = vec_1->at(0) * vec_2->at(1) - vec_1->at(1) * vec_2->at(0);
    
    return result;
}