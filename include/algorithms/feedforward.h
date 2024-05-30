#include "math/vector.h"
#include "math/matrix.h"
#include "network.h"
#include "layer.h"

double sigmoid(double x);

void feedfordward( Vector * input, Vector * neurons, Layer * current);
void run_feedforward(Network * network, Vector * expected, Vector * input);