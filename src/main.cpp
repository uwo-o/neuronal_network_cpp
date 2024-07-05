#include <iostream>

#include "network.h"

using namespace std;

static const int INPUT_SIZE = 2;
static const int HIDDEN_SIZE = 3;
static const int OUTPUT_SIZE = 1;

int main() {
    
    Network network(INPUT_SIZE, HIDDEN_SIZE, OUTPUT_SIZE);
    network.describe();

    return 0;
}