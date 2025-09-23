#ifndef LAYERS_H
#define LAYERS_H

#include <Eigen/Dense>
#include <vector>

class Linear
{
public:
    Linear(int inputSize, int outputSize);
    Eigen::MatrixXd forward(const Eigen::MatrixXd &input);
    Eigen::MatrixXd backward(const Eigen::MatrixXd &gradOutput, double learningRate);
    Eigen::MatrixXd weights;
    Eigen::MatrixXd bias;
};

class Layer
{
public:
    virtual Eigen::MatrixXd forward(const Eigen::MatrixXd &input) = 0;
    virtual Eigen::MatrixXd backward(const Eigen::MatrixXd &gradOutput, double learningRate) = 0;
    virtual ~Layer() {}
    Linear *linearLayer;
};

#endif