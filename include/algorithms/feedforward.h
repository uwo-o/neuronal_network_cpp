#include "math/vector.h"
#include "math/matrix.h"
#include "network.h"
#include "layer.h"

double sigmoid(double x);

Vector * feedfordward( Vector * input, Layer * current);
Vector * run_feedforward(Network * network, Vector * input);