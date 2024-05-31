#include <iostream>
#include <math.h>

#include "network.h"
#include "algorithms/feedforward.h"

int main(int argc, char * argv[]){


    Network * network = new Network(3, 2, 1, 0.8);
    network->set_name("test");

    Vector * prev_out = network->get_layer(0)->get_neurons();
    prev_out->print();

    Vector * input = new Vector(3);

    Vector * output =run_feedforward(network, input);

    output->print();

    return 0;
}
