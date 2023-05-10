#include <iostream>
#include <fstream>
#include <string>

#include "matrix.hpp"
#include "neuron.hpp"
#include "transform.hpp"

int main(int argc, char * argv[]){

    std::ifstream file("./models/celcius_to_farenheit/model.txt");

    if(!file.is_open()){
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    int input_size, output_size, hidden_layers, hidden_layers_size;

    file >> input_size;
    file >> output_size;
    file >> hidden_layers;
    file >> hidden_layers_size;

    std::cout << input_size << " " << output_size << " " << hidden_layers << " " << hidden_layers_size << std::endl;

    file.close();

    return 0;
}