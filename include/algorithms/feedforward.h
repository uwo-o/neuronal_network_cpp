#include "math/matrix.h"
#include "math/activation.h"
#include "math/vector.h"
#include "network.h"
#include "layer.h"

Vector * feedfordward( Vector * input, Layer * current);
Vector * run_feedforward(Network * network, Vector * input);