#ifndef NETWORK_H
#define NETWORK_H

#include <Eigen/Dense>
#include <iostream>
#include <vector>

#include "activation_functions.h"

class Network
{
private:
  int layers = 0;

  Eigen::MatrixXd hidden;
  Eigen::VectorXd output;

  Eigen::MatrixXd hidden_b;
  Eigen::VectorXd output_b;

  bool has_hidden;
  double (*activation_function)(double);
  double (*d_activation_function)(double);

  double cost_function(Eigen::VectorXd value, Eigen::VectorXd expected);
  double d_cost_function(double value, double expected);
  void train(Eigen::VectorXd value, Eigen::VectorXd expected, double learning_rate);
  double get_pond_prev(int layer);

public:
  Network(int hidden, int hidden_layers, int output);
  ~Network();
  Eigen::VectorXd forward(Eigen::VectorXd input);
  double backpropagation(int i, double, double learning_rate, int neuron);
  void set_activation_function(double (*activation_function)(double));
  void set_d_activation_function(double (*activation_function)(double));
  void start_training(std::vector<std::vector<Eigen::VectorXd>>, int, double);
  void predict();
  void save();
  void load();
  void describe();
};

#endif