#include "activation_functions.h"

using Eigen::MatrixXd;

MatrixXd linear(const MatrixXd &v)
{
    return v;
}

MatrixXd d_linear(const MatrixXd &v)
{
    return MatrixXd::Ones(v.rows(), v.cols());
}

MatrixXd ReLu(const MatrixXd &v)
{
    return v.cwiseMax(0.0);
}

MatrixXd d_ReLu(const MatrixXd &v)
{
    return (v.array() > 0).cast<double>();
}

MatrixXd sigmoid(const MatrixXd &v)
{
    return 1.0 / (1.0 + (-v.array()).exp());
}

MatrixXd d_sigmoid(const MatrixXd &v)
{
    MatrixXd s = sigmoid(v);
    return s.array() * (1.0 - s.array());
}

MatrixXd softmax(const MatrixXd &v)
{
    MatrixXd result = v;
    for (int i = 0; i < v.rows(); ++i)
    {
        double maxCoeff = v.row(i).maxCoeff();
        Eigen::ArrayXd exps = (v.row(i).array() - maxCoeff).exp();
        result.row(i) = exps / exps.sum();
    }
    return result;
}

MatrixXd d_softmax(const MatrixXd &v)
{
    MatrixXd s = softmax(v);
    return s.array() * (1.0 - s.array());
}