#include <vector>

#include "math/activation.h"
#include "math/functions.h"
#include "layer.h"
#include "network.h"

void backpropagation(Network * net, double learning_rate,  std::vector<double> *deltas, int current_layer);
void run_backpropagation(Network * net, std::vector<double> *expected, double learning_rate);