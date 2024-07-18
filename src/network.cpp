#include "network.h"

Network::Network(int hidden_size, int hidden_layers, int output_size)
{
    if (hidden_size != 0 || hidden_layers != 0)
    {
        this->hidden = Eigen::MatrixXd(hidden_size, hidden_layers);
        this->hidden.setRandom();

        this->output = Eigen::VectorXd(output_size);
        this->output.setRandom();

        this->hidden_b = Eigen::MatrixXd(hidden_size, hidden_layers);
        this->hidden_b.setRandom();

        this->output_b = Eigen::VectorXd(output_size);
        this->output_b.setRandom();

        this->has_hidden = true;
    }
    else
    {
        this->output = Eigen::VectorXd(output_size);
        this->output.setRandom();

        this->output_b = Eigen::VectorXd(output_size);
        this->output_b.setRandom();

        this->has_hidden = false;
    }
}

Network::~Network()
{
}

void Network::describe()
{
    if (has_hidden)
    {
        std::cout << "-------------------\n";
        std::cout << "Hidden layer:\n";
        std::cout << "===================\n";
        std::cout << "Weigths:\n";
        std::cout << this->hidden << std::endl;
        std::cout << "Biases:\n";
        std::cout << this->hidden_b;
        std::cout << std::endl;
        }
    std::cout << "-------------------\n";
    std::cout << "Output layer:\n";
    std::cout << "===================\n";
    std::cout << "Weigths:\n";
    std::cout << this->output << std::endl;
    std::cout << "Biases:\n";
    std::cout << this->output_b;
    std::cout << std::endl;
    std::cout << "-------------------\n";
}

Eigen::VectorXd Network::forward(Eigen::VectorXd input)
{

    if (!has_hidden)
    {
        Eigen::VectorXd result(this->output.size());

        for (int i = 0; i < this->output.size(); ++i)
        {
            for (int j = 0; j < input.size(); ++j)
            {
                result(i) = input(j) * this->output(i);
            }
        }

        result += this->output_b;

        return result;
    }

    Eigen::MatrixXd step_1(this->hidden.cols(), this->hidden.rows());
    step_1.setZero();

    for (int i = 0; i < this->hidden.cols(); ++i)
    {
        for (int j = 0; j < input.size(); ++j)
        {
            step_1(0, i) = input(j) * this->hidden(0, i);
        }
    }

    step_1.col(0) += this->hidden_b.col(0);

    for (int i = 1; i < this->hidden.cols(); ++i)
    {
        for (int j = 0; j < this->hidden.rows(); ++j)
        {
            for (int k = 0; k < this->hidden.rows(); ++k)
            {
                step_1(i, j) = step_1(i - 1, k) * this->hidden(i, j);
            }
        }
        step_1.col(i) += this->hidden_b.col(i);
    }

    Eigen::VectorXd step_2(this->output.size());

    for (int i = 0; i < this->output.size(); ++i)
    {
        for (int j = 0; j < this->hidden.rows(); ++j)
        {
            step_2(i) = step_1(this->hidden.cols() - 1, j) * this->output(i);
        }
    }

    step_2 += this->output_b;

    return step_2;
}