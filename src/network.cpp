#include "network.h"

double Network::cost_function(Eigen::VectorXd value, Eigen::VectorXd expected)
{
    Eigen::VectorXd diff = expected - value;
    Eigen::VectorXd diff_s = diff * diff;

    return diff_s.sum() / 2;
}

double Network::d_cost_function(double value, double expected)
{
    return value - expected;
}

Network::Network(int hidden_size, int hidden_layers, int output_size)
{
    if (hidden_size != 0 && hidden_layers != 0)
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
        this->layers += hidden_layers;
    }
    else
    {
        this->output = Eigen::VectorXd(output_size);
        this->output.setRandom();

        this->output_b = Eigen::VectorXd(output_size);
        this->output_b.setRandom();

        this->has_hidden = false;
    }

    this->layers += 1;
    this->activation_function = linear;
}

Network::~Network()
{
}

void Network::set_activation_function(double (*activation_function)(double))
{
    this->activation_function = activation_function;
}

void Network::set_d_activation_function(double (*d_activation_function)(double))
{
    this->d_activation_function = d_activation_function;
}

void Network::backpropagation(int layer, double error, double learning_rate)
{

    if (layer < 0)
        return;

    for (int i = 0; i < this->hidden.rows(); ++i)
    {
        double a = this->hidden(i, layer);
        this->hidden(i, layer) -= error * a * learning_rate;
    }

    for (int i = this->hidden.cols() - 2; i >= 0; --i)
    {
        for (int j = 0; j < this->hidden.rows(); ++j)
        {
            double a = this->hidden(j, i);
            this->hidden(j, i) -= this->hidden(j, i + 1) * a * learning_rate;
        }
    }
}

void Network::train(Eigen::VectorXd value, Eigen::VectorXd expected, double learning_rate)
{

    double pond_error = 0;

    for (int i = 0; i < output.size(); ++i)
    {
        double d_cost_value = this->d_cost_function(value[i], expected[i]);
        // TO-DO CHANGE IT FOR VARIABLE FUNCTION
        double error = d_linear(d_cost_value) * d_cost_value;
        pond_error += error;

        double a = this->output[i];

        this->output[i] -= error * a * learning_rate;
        this->output_b[i] -= error * learning_rate;
    }

    pond_error /= this->output.size();

    int hidden_cols = 0;

    if (has_hidden)
        hidden_cols = this->hidden.cols();

    backpropagation(hidden_cols - 1, pond_error, learning_rate);
}

void Network::start_training(std::vector<std::vector<Eigen::VectorXd>> training_set, int times, double learning_rate)
{
    for (int i = 0; i < times; ++i)
    {
        for (int j = 0; j < training_set.size(); ++j)
        {
            Eigen::VectorXd out = this->forward(training_set[j][0]);
            double error = this->cost_function(out, training_set[j][1]);
            this->train(out, training_set[j][1], learning_rate);
        }
    }
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

    Eigen::MatrixXd step_1(this->hidden.rows(), this->hidden.cols());
    step_1.setZero();

    for (int i = 0; i < this->hidden.cols(); ++i)
    {
        for (int j = 0; j < input.size(); ++j)
        {
            step_1(0, i) += input(j) * this->hidden(0, i);
        }
    }

    step_1.col(0) += this->hidden_b.col(0);

    // hasta aqui Ok

    for (int i = 0; i < step_1.cols(); ++i)
    {
        for (int j = 0; j < step_1.rows(); ++j)
        {
            for (int k = 0; k < step_1.rows(); ++k)
            {
                if (i + 1 > step_1.cols() - 1)
                    continue;

                step_1(j, i + 1) += step_1(k, i) * this->hidden(i, j);
            }
        }
        step_1.col(i) += this->hidden_b.col(i);
    }

    Eigen::VectorXd step_2(this->output.size());

    for (int i = 0; i < this->output.size(); ++i)
    {
        for (int j = 0; j < this->hidden.rows(); ++j)
        {
            step_2(i) += step_1(j, this->hidden.cols() - 1) * this->output(i);
        }

        step_2(i) += this->output_b(i);
        step_2(i) = linear(step_2(i));
    }

    return step_2;
}