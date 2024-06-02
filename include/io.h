#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <set>

struct Data {
    std::vector<double> expected;
    std::vector<std::vector<double>> inputs;
    int size;
};

Data read_csv(std::string filename);
static void write_csv(std::string filename, std::vector<Data> data);
Data normalize_data_zero_to_one(Data data);

#endif