#include "layers.h"

Layer::Layer(int input_size, int output_size) {
    this->weights = Eigen::MatrixXd::Random(input_size, output_size) * sqrt(2.0 / input_size);
    this->bias = Eigen::MatrixXd::Zero(1, output_size);
}

Eigen::MatrixXd Linear::forward(const Eigen::MatrixXd &input) {
    this->input_cache = input;
    return input * this->weights + this->bias;
}

Eigen::MatrixXd Linear::backward(const Eigen::MatrixXd &gradOutput, double learningRate) {
    return gradOutput;
}


Linear::Linear(int inputSize, int outputSize) : Layer(inputSize, outputSize) {}

ReLU::ReLU(int inputSize) : Layer(inputSize, inputSize) {}

Eigen::MatrixXd ReLU::forward(const Eigen::MatrixXd &input) {
    return ReLu(input);
}

Eigen::MatrixXd ReLU::backward(const Eigen::MatrixXd &gradOutput, double learningRate) {
    return gradOutput;
}