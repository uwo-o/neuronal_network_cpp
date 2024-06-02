#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void acumulate(std::vector<double> * vec, int pos, int value);
void sustraction(std::vector<double> * vec_1, std::vector<double> * vec_2);
std::vector<double> * copy(std::vector<double> *);
double sum_elements(std::vector<double> * vec);
std::vector<std::vector<double>*> * transpose(std::vector<std::vector<double>*> * matrix);

void randomize_vector(std::vector<double> * vec);
void randomize_matrix(std::vector<std::vector<double>*> * matrix);

#endif