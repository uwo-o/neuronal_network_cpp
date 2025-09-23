#include "network.h"

using namespace std;
using Eigen::MatrixXd;

Network::Network(std::vector<std::unique_ptr<Layer>> layers, float learning_rate) {
    this->layers = std::move(layers);
}

Network::~Network() {}

Eigen::MatrixXd Network::forward(const Eigen::MatrixXd &input)
{
    Eigen::MatrixXd activation = input;
    for (const auto &layer : layers)
    {
        activation = layer->forward(activation);
    }
    return activation;
}