#include <iostream>
#include <cstdlib>
#include <time.h>

#include "network.h"
#include "data_loader.h"
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(0));
    DataLoader data_loader;

    Eigen::MatrixXd train_data = DataLoader::loadCSV("../data/mnist_train_small.csv", false, ',');
    Eigen::MatrixXd test_data = DataLoader::loadCSV("../data/mnist_test.csv", false, ',');

    cout << "Train data shape: (" << train_data.rows() << ", " << train_data.cols() << ")" << endl;
    cout << "Test data shape: (" << test_data.rows() << ", " << test_data.cols() << ")" << endl;

    Eigen::MatrixXd X = train_data.rightCols(train_data.cols() - 1);
    Eigen::MatrixXd y = train_data.leftCols(1);

    Eigen::MatrixXd X_test = test_data.rightCols(test_data.cols() - 1);
    Eigen::MatrixXd y_test = test_data.leftCols(1);

    Eigen::MatrixXd X_train, X_val, y_train, y_val;
    data_loader.splitData(X, y, X_train, X_val, y_train, y_val, 0.8);

    std::cout << "X_train shape: (" << X_train.rows() << ", " << X_train.cols() << ")" << std::endl;
    std::cout << "y_train shape: (" << y_train.rows() << ", " << y_train.cols() << ")" << std::endl;
    std::cout << "X_val shape: (" << X_val.rows() << ", " << X_val.cols() << ")" << std::endl;
    std::cout << "y_val shape: (" << y_val.rows() << ", " << y_val.cols() << ")" << std::endl;
    std::cout << "X_test shape: (" << X_test.rows() << ", " << X_test.cols() << ")" << std::endl;
    std::cout << "y_test shape: (" << y_test.rows() << ", " << y_test.cols() << ")" << std::endl;

    std::vector<std::unique_ptr<Layer>> layers;
    layers.push_back(std::make_unique<Linear>(X_train.cols(), 256));
    layers.push_back(std::make_unique<ReLU>(256));
    layers.push_back(std::make_unique<Linear>(256, 128));
    layers.push_back(std::make_unique<ReLU>(128));
    layers.push_back(std::make_unique<Linear>(128, 64));
    layers.push_back(std::make_unique<ReLU>(64));
    layers.push_back(std::make_unique<Linear>(64, 32));
    layers.push_back(std::make_unique<ReLU>(32));
    layers.push_back(std::make_unique<Linear>(32, 10));
    layers.push_back(std::make_unique<Softmax>(10));

    Network network(std::move(layers));
    // network.train(X_train, y_train, 10);
    // float accuracy = network.evaluate(X_test, y_test);
    // std::cout << "Test accuracy: " << accuracy << std::endl;

    return 0;
}