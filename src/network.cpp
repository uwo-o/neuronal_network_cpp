#include "network.h"

Network::Network(int input_size, int hidden_size, int hidden_layers, int output_size)
{
    this->input = Eigen::MatrixXd(input_size, hidden_size);
    this->input.setRandom();

    this->hidden = Eigen::MatrixXd(hidden_size, hidden_layers);
    this->hidden.setRandom();

    this->output = Eigen::MatrixXd(hidden_layers, output_size);
    this->output.setRandom();
}

Network::~Network()
{
}

void Network::describe()
{
    std::cout << "Input:\n"
              << this->input << std::endl;
    std::cout << "Hidden:\n"
              << this->hidden << std::endl;
    std::cout << "Output:\n"
              << this->output << std::endl;
}