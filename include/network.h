#ifndef NETWORK_H
#define NETWORK_H

#include <Eigen/Dense>
#include <iostream>
#include <vector>
#include <memory>

#include "activation_functions.h"
#include "layers.h"
class Network
{
private:
  std::vector<std::unique_ptr<Layer>> layers;
  float learning_rate;

public:
  Network(std::vector<std::unique_ptr<Layer>> layers, float learning_rate = 0.01);
  ~Network();
  Eigen::MatrixXd forward(const Eigen::MatrixXd &input);
  void backward(const Eigen::MatrixXd &predicted, const Eigen::MatrixXd &actual);
  void train(const Eigen::MatrixXd &X_train, const Eigen::MatrixXd &y_train, int epochs);
  float evaluate(const Eigen::MatrixXd &X_val, const Eigen::MatrixXd &y_val);
};

#endif