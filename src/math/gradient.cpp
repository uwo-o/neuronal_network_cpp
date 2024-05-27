#include "math/gradient.h"

Gradient::Gradient(double (*d_activation)(double)){
    this->d_activation = d_activation;
}

Vector ** Gradient::calculate(Vector *current, Vector *prev, Vector *errors){

    Vector ** gradients = new Vector*[current->get_size()];

    double dc_dw = 0;
    double dc_db = 0;

    for(int i = 0; i < current->get_size(); i++){
        dc_dw = prev->get(i) * (d_activation(current->get(i))) * 2 * errors->get(i);
        dc_db = (d_activation(current->get(i))) * 2 * errors->get(i);

        Vector * gradient = new Vector(2);
        gradient->set(0, dc_dw);
        gradient->set(1, dc_db);

        gradients[i] = gradient;
    }

    return gradients;
}