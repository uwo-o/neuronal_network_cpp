#include "layers.h"

Linear::Linear(int inputSize, int outputSize)
{
    this->weights = Eigen::MatrixXd::Random(inputSize, outputSize) * sqrt(2.0 / inputSize);
    this->bias = Eigen::MatrixXd::Zero(1, outputSize);
}

Eigen::MatrixXd Layer::forward(const Eigen::MatrixXd &input)
{
    return (input * weights).rowwise() + bias;
}
