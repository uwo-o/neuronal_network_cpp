#include "transform.h"

double * apply_function(double * parents, Matrix * matrix, double slant){

    double * vector;

    for(int i=0; i<(*matrix).rows; i++){
        for(int j=0; j<(*matrix).cols; j++){
            vector[i] += (*matrix).matrix_pointer[i][j]*parents[j];
        }
        vector[i]+=slant;
    }

    return vector;
};