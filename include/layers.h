#ifndef LAYERS_H
#define LAYERS_H

#include <Eigen/Dense>
#include <vector>
#include "activation_functions.h"

class Layer
{
public:
    Layer(int input_size, int output_size);
    virtual ~Layer() {}

    virtual Eigen::MatrixXd forward(const Eigen::MatrixXd &input) = 0;
    virtual Eigen::MatrixXd backward(const Eigen::MatrixXd &gradOutput, double learningRate) = 0;

    Eigen::MatrixXd weights;
    Eigen::MatrixXd bias;
    Eigen::MatrixXd input_cache;
};

class Linear : public Layer
{
public:
    Linear(int inputSize, int outputSize);

    Eigen::MatrixXd forward(const Eigen::MatrixXd &input) override;
    Eigen::MatrixXd backward(const Eigen::MatrixXd &gradOutput, double learningRate) override;
};

class ReLU : public Layer
{
public:
    ReLU(int inputSize);

    Eigen::MatrixXd forward(const Eigen::MatrixXd &input) override;
    Eigen::MatrixXd backward(const Eigen::MatrixXd &gradOutput, double learningRate) override;
};

#endif