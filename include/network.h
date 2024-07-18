#ifndef NETWORK_H
#define NETWORK_H

#include <Eigen/Dense>
#include <iostream>
class Network
{
private:
  Eigen::MatrixXd hidden;
  Eigen::VectorXd output;

  Eigen::MatrixXd hidden_b;
  Eigen::VectorXd output_b;

  bool has_hidden;

public:
  Network(int hidden, int hidden_layers, int output);
  ~Network();
  Eigen::VectorXd forward(Eigen::VectorXd input);
  void backpropagation();
  void train();
  void predict();
  void save();
  void load();
  void describe();
};

#endif