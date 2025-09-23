#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <cmath>
#include <Eigen/Dense>

Eigen::MatrixXd ReLu(const Eigen::MatrixXd &);
Eigen::MatrixXd d_ReLu(const Eigen::MatrixXd &);

Eigen::MatrixXd sigmoid(const Eigen::MatrixXd &);
Eigen::MatrixXd d_sigmoid(const Eigen::MatrixXd &);

Eigen::MatrixXd linear(const Eigen::MatrixXd &);
Eigen::MatrixXd d_linear(const Eigen::MatrixXd &);

Eigen::MatrixXd softmax(const Eigen::MatrixXd &);
Eigen::MatrixXd d_softmax(const Eigen::MatrixXd &);

#endif