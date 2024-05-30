#include <iostream>
#include <math.h>

#include "network.h"
#include "algorithms/feedforward.h"

int main(int argc, char * argv[]){


    Network * network = new Network(2, 1, 1, 0.8);
    network->set_name("test");
    network->describe();
    network->fdescribe();

    Vector * input = new Vector(2);
    input->insert(0, 1);
    input->insert(1, 2);

    Vector * expected = new Vector(2);
    expected->insert(0, 0);
    expected->insert(1, 0);

    run_feedforward(network, expected, input);

    return 0;
}
