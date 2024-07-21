#include <iostream>
#include <cstdlib>
#include <time.h>

#include "network.h"
#include <unistd.h>

using namespace std;

static const int INPUT_SIZE = 1;
static const int HIDDEN_SIZE = 0;
static const int HIDDEN_LAYERS = 0;
static const int OUTPUT_SIZE = 1;
static const float LEARN_RATE = 0.00001;

int main()
{
    Network n = Network(HIDDEN_SIZE, HIDDEN_LAYERS, OUTPUT_SIZE);

    n.set_activation_function(&sigmoid);
    n.describe();

    Eigen::VectorXd input(INPUT_SIZE);
    input(0) = 100;

    cout << n.forward(input) << endl;

    Eigen::VectorXd output(OUTPUT_SIZE);
    output(0) = 212;

    Eigen::VectorXd data_set[] = {input, output};

    n.start_training(data_set, 10000, LEARN_RATE);

    n.describe();

    cout << n.forward(input) << endl;

    return 0;
}