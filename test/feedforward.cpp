#include "gtest/gtest.h"
#include "algorithms/feedforward.h"
#include "layer.h"
#include <vector>

#include <iostream>

//TEST (FEEDFORDWARD, Test_1) {
//    Network * network = new Network(1, 1, 1, 1, 0.8);
//    network->set_name("test");
//
//    Vector * input = new Vector(2);
//    input->set(0, 1);
//    input->set(1, 2);
//
//    Vector * output = run_feedforward(network, input);
//    output->print();
//}
//
//TEST (FEEDFORDWARD, Test_2) {
//    Network * network = new Network(1, 0, 0, 1, 0.8);
//    network->set_name("test");
//
//    Vector * input = new Vector(2);
//    input->set(0, 1);
//    input->set(1, 2);
//
//    Vector * output = run_feedforward(network, input);
//    output->print();
//}