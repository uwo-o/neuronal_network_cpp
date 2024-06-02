#include "io.h"

Data * read_csv(std::string filename){
    std::ifstream file;
    
    file.open(filename);

    std::string line;
    Data * data = new Data();

    if (!file.is_open()){
        std::cout << "Error opening file" << std::endl;
        return data;
    }

    std::cout << "Reading file: " << filename << std::endl;

    data->expected = new std::vector<double>();
    data->inputs = new std::vector<std::vector<double> *>();

    while (std::getline(file, line)){
        std::stringstream ss(line);
        std::string token;
        int i = 0;
        std::vector<double> * input = new std::vector<double>();
        while (std::getline(ss, token, ',')){
            if (i == 0){
                data->expected->push_back(std::stod(token));
            } else {
                input->push_back(std::stod(token));
            }
            i++;
        }
        data->size++;
        data->inputs->push_back(input);
    }

    std::cout << "File read" << std::endl;

    return data;
}

void normalize_data_zero_to_one(Data * data){

    for (int i = 0; i < data->inputs->size(); i++){ 
        for (int j = 0; j < data->inputs->at(i)->size(); j++){
            data->inputs->at(i)->at(j) /= 255;
        }
    }
}