#include "network.hpp"

using namespace std;

void neurone_connector(Neuron * input_neurons, Neuron * output_neurons, Neuron * hidden_neurons, int input_size, int output_size, int hidden_layers, int hidden_layers_size){

}

Network * create_network(int input_size, int output_size, int hidden_layers, int hidden_layers_size){

    vector<Neuron> * input_neurons = new std::vector<Neuron>(input_size);
    vector<Neuron> * output_neurons = new std::vector<Neuron>(output_size);
    vector<Neuron> * hidden_neurons = new std::vector<Neuron>(hidden_layers*hidden_layers_size);

    Network * network = new Network;
}

Network * load_model(int argc, char * argv[]){

    ifstream file("./models/celcius_to_farenheit/model.txt");

    if(!file.is_open()){
        cout << "Error opening file" << std::endl;
        return NULL;
    }


    int input_size, output_size, hidden_layers, hidden_layers_size;

    file >> input_size;
    file >> output_size;
    file >> hidden_layers;
    file >> hidden_layers_size;

    cout << input_size << " " << output_size << " " << hidden_layers << " " << hidden_layers_size << std::endl;

    file.close();
}