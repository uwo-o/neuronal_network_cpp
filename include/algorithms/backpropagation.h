#include "math/activation.h"
#include "math/vector.h"
#include "math/matrix.h"
#include "layer.h"

void backpropagation(Layer * current, int size, double cost, double learning_rate, Vector * expected);