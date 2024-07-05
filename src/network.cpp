#include "network.h"

Network::Network(int input_size, int hidden_size, int output_size) {
    this->input = Eigen::MatrixXd(input_size, 1);
    this->input.setRandom();

    this->hidden = Eigen::MatrixXd(hidden_size, input_size);
    this->hidden.setRandom();

    this->output = Eigen::MatrixXd(output_size, hidden_size);
    this->output.setRandom();
}

Network::~Network() {
}

void Network::describe() {
    std::cout << "Input:\n" << this->input << std::endl;
    std::cout << "Hidden:\n" << this->hidden << std::endl;
    std::cout << "Output:\n" << this->output << std::endl;
}