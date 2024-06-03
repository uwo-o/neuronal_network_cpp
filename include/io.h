#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <vector>

struct Data {
    std::vector<double> *expected;
    std::vector<std::vector<double> *> *outputs;
    std::vector<std::vector<double> *> *inputs;
    int size;
};

Data * read_csv(std::string filename);
void write_csv(std::string filename, std::vector<Data> data);
void normalize_data_zero_to_one(Data * data);

#endif