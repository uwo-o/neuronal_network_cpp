#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

#include "utils/garbage.h"

void acumulate(std::vector<double> * vec, int pos, int value);
void sustraction(std::vector<double> * vec_1, std::vector<double> * vec_2);
std::vector<double> * copy(std::vector<double> *);
double sum_elements(std::vector<double> * vec);
std::vector<std::vector<double>*> * transpose(std::vector<std::vector<double>*> * matrix);

void randomize_vector(std::vector<double> * vec);
void randomize_matrix(std::vector<std::vector<double>*> * matrix);

double dot(std::vector<double> * vec_1, std::vector<double> * vec_2);

std::vector<double> * vec_sub(std::vector<double> * vec_1, std::vector<double> * vec_2);
std::vector<double> * vec_scalar(std::vector<double> * vec_1, double scalar);
std::vector<double> * vec_apply(std::vector<double> * vec_1, double (*f)(double));
std::vector<double> * vec_mult(std::vector<double> * vec_1, std::vector<double> * vec_2);
std::vector<double> * vec_mult(std::vector<std::vector<double>  *> * matrix, std::vector<double> * vec);
std::vector<double> * vec_cross(std::vector<double> * vec_1, std::vector<double> * vec_2);

#endif