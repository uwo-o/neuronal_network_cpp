#ifndef NETWORK_H
#define NETWORK_H

#include <Eigen/Dense>
#include <iostream>
class Network {
  private:
    Eigen::MatrixXd input;
    Eigen::MatrixXd hidden;
    Eigen::MatrixXd output;
    public:
        Network(int input, int hidden, int output);
        ~Network();
        void forward();
        void backward();
        void train();
        void predict();
        void save();
        void load();
        void describe();
};

#endif