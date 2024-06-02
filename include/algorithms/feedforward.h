
#include "math/activation.h"
#include "math/functions.h"
#include "network.h"
#include "layer.h"

std::vector<double> * feedfordward( std::vector<double> * input, Layer * current, double (activation)(double));
std::vector<double> * run_feedforward(Network * network, std::vector<double> * input);