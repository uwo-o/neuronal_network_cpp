#include "data_loader.h"
#include <iostream>
#include <algorithm>

Eigen::MatrixXd DataLoader::loadCSV(const std::string &filePath, bool hasHeader, char delimiter)
{
    std::ifstream file(filePath);
    if (!file.is_open())
        throw std::runtime_error("The file: " + filePath + " could not be opened.");

    std::vector<std::vector<double>> values;
    std::string line;

    if (hasHeader)
        std::getline(file, line);

    while (std::getline(file, line))
    {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, delimiter))
        {
            row.push_back(std::stod(cell));
        }
        values.push_back(row);
    }

    if (values.empty())
        throw std::runtime_error("Empty CSV " + filePath);

    size_t rows = values.size();
    size_t cols = values[0].size();

    Eigen::MatrixXd mat(rows, cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            mat(i, j) = values[i][j];

    return mat;
}

void DataLoader::splitData(const Eigen::MatrixXd &X,
                           Eigen::MatrixXd &y,
                           Eigen::MatrixXd &X_train,
                           Eigen::MatrixXd &X_val,
                           Eigen::MatrixXd &y_train,
                           Eigen::MatrixXd &y_val,
                           double trainRatio)
{
    int n = X.rows();
    int nTrain = static_cast<int>(n * trainRatio);
    int nVal = n - nTrain;

    X_train = X.topRows(nTrain);
    X_val = X.bottomRows(nVal);

    y_train = y.topRows(nTrain);
    y_val = y.bottomRows(nVal);
}
