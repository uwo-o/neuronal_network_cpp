#include "math/activation.h"
#include "math/vector.h"
#include "math/matrix.h"
#include "layer.h"
#include "network.h"

void backpropagation(Network * net, Vector *expected, double learning_rate);