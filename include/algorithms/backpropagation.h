#include <vector>

#include "math/activation.h"
#include "math/functions.h"
#include "layer.h"
#include "network.h"

void backpropagation(Network * net, std::vector<double> *expected, double learning_rate);