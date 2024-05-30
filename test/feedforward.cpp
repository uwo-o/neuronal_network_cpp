#include "gtest/gtest.h"
#include "algorithms/feedforward.h"
#include "layer.h"
#include "math/vector.h"
#include "math/matrix.h"

#include <iostream>

TEST (FEEDFORDWARD, Test_1) {
    Network * network = new Network(2, 1, 1, 0.8);
    network->set_name("test");

    Vector * input = new Vector(2);
    input->insert(0, 1);
    input->insert(1, 2);

    Vector * output = run_feedforward(network, input);
    output->print();
}

TEST (FEEDFORDWARD, Test_2) {
    Network * network = new Network(1, 0, 1, 0.8);
    network->set_name("test");

    Vector * input = new Vector(2);
    input->insert(0, 1);
    input->insert(1, 2);

    Vector * output = run_feedforward(network, input);
    output->print();
}