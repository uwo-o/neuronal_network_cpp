#include "network.h"

using namespace std;
using Eigen::MatrixXd;

Network::Network(std::vector<Eigen::MatrixXd> layers, float learning_rate) : layers(layers) {}
Network::~Network() {}

Eigen::MatrixXd Network::forward(const Eigen::MatrixXd &input)
{
    Eigen::MatrixXd activation = input;
    for (const auto &layer : layers)
    {
        activation = (activation * layer.weights) + layer.bias;
        activation = ReLu(activation);
    }
    return activation;
}