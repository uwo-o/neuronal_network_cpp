#include <iostream>
#include <math.h>

#include "network.h"

int main(int argc, char * argv[]){


    Network * network = new Network(2, 1, 1, 0.8);
    network->set_name("test");
    network->describe();
    network->fdescribe();

    return 0;
}
