#include <iostream>

#include "Eigen/Dense"

using namespace std;

static const int INPUT_SIZE = 2;
static const int HIDDEN_SIZE = 3;
static const int OUTPUT_SIZE = 1;

int main() {
    
    Eigen::MatrixXd input(INPUT_SIZE, 1);
    input.setRandom();

    Eigen::MatrixXd iw(HIDDEN_SIZE, INPUT_SIZE);
    iw.setRandom();

    Eigen::MatrixXd weights(OUTPUT_SIZE, HIDDEN_SIZE);
    weights.setRandom();

    Eigen::MatrixXd wo(OUTPUT_SIZE, HIDDEN_SIZE);
    wo.setRandom();

    Eigen::MatrixXd output(OUTPUT_SIZE, 1);
    output.setZero();

    return 0;
}