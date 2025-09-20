#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <Eigen/Dense>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

class DataLoader
{
public:
    DataLoader() = default;
    ~DataLoader() = default;
    static Eigen::MatrixXd loadCSV(const std::string &filePath, bool hasHeader = false, char delimiter = ',');
    static void splitData(const Eigen::MatrixXd &X,
                          Eigen::MatrixXd &y,
                          Eigen::MatrixXd &X_train,
                          Eigen::MatrixXd &X_val,
                          Eigen::MatrixXd &y_train,
                          Eigen::MatrixXd &y_val,
                          double trainRatio = 0.7);
};
#endif
