#include <iostream>
#include <math.h>

#include "network.h"
#include "algorithms/feedforward.h"

int main(int argc, char * argv[]){


    Network * network = new Network(2, 2, 5, 0.8);
    network->set_name("test");

    Vector * input = new Vector(2);
    input->insert(0, 1);
    input->insert(1, 2);

    Vector * output =run_feedforward(network, input);

    return 0;
}
