#include "transform.hpp"

/*
sigmoide

- double x: The value to apply the function

- return evaluated value
*/
double sigmoide(double x){
    return 1/(1+exp(-x));
}

/*
apply_function

- Neurone * vector: The array that has every neuron in the layer
- Matrix * matrix: The pointer that has the matrix struct, inside is the matrix_pointer

    This function gets an array with neurons and theri quantity, a matrix structure, and a slant
    then applies the dot product between the matrix and the vector, next add the slant.

- return double sigmoide(value): Applies the sigmoide value and return the result
*/
double apply_function(Neuron * vector, Matrix * matrix, double slant, int neurons_quantity){

    double result = 0;

    for(int i=0; i<(*matrix).rows; i++){
        for(int j=0; j<(*matrix).cols; j++){
            result += (*matrix).matrix_pointer[i][j]*vector[j].value;
        }
        result+=slant;
    }

    return sigmoide(result);
};
