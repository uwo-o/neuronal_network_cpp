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
static const float LEARN_RATE = 0.001;

int main()
{
    Network n = Network(HIDDEN_SIZE, HIDDEN_LAYERS, OUTPUT_SIZE);

    n.set_activation_function(&sigmoid);
    n.describe();

    std::vector<std::vector<Eigen::VectorXd>> training_set;

    for (int i = 0; i < 30; ++i)
    {
        Eigen::VectorXd input(INPUT_SIZE);
        input(0) = i * 10;
        Eigen::VectorXd output(OUTPUT_SIZE);
        output(0) = (1.8 * input(0)) + 32;

        std::vector<Eigen::VectorXd>
            train_pair = {input, output};

        training_set.push_back(train_pair);
    }

    n.start_training(training_set, 50000, LEARN_RATE);

    n.describe();

    return 0;
}