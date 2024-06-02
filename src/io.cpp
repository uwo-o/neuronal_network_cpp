#include "io.h"

Data read_csv(std::string filename){
    std::ifstream file;
    
    file.open(filename);

    std::string line;
    Data data = Data();

    if (!file.is_open()){
        std::cout << "Error opening file" << std::endl;
        return data;
    }

    std::cout << "Reading file: " << filename << std::endl;

    // read data with the following format in lines:
    // expected, feature1, feature2, feature3, ..., featureN
    while (std::getline(file, line)){
        std::vector<double> features;
        std::stringstream ss(line);
        std::string token;
        bool is_expected = true;
        while (std::getline(ss, token, ',')){
            if (is_expected){
                data.expected.push_back(std::stod(token));
                is_expected = false;
            } else {
                features.push_back(std::stod(token));
            }
        }
        data.inputs.push_back(features);
        data.size++;
    }

    file.close();
    std::cout << "File read" << std::endl;

    return data;
}

Data normalize_data_zero_to_one(Data data){

    for (int i = 0; i < data.inputs.size(); i++){ 
        for (int j = 0; j < data.inputs[i].size(); j++){
            data.inputs[i][j] = data.inputs[i][j] / 255;
        }
    }

    return data;
}