#include "activation_functions.hpp"
/*
sigmoide

- double x: The value to apply the function

- return evaluated value
*/
double sigmoide(double x){
    return 1/(1+exp(-x));
}

/*
ReLU
 
- double x: The value to apply the function
 
- return evaluated value
*/
double ReLU(double x){
	return x > 0 ? x : 0;
}
