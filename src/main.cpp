#include <iostream>
#include <math.h>

#include "network.h"

int main(int argc, char * argv[]){


    Network * network = new Network(1, 0, 1, 0.8);
    network->set_name("XOR");
    network->describe();
    network->fdescribe();

    return 0;
}
