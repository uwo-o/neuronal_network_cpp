#include "network.hpp"

void neurone_connector(Neuron * input_neurons, Neuron * output_neurons, Neuron * hidden_neurons, int input_size, int output_size, int hidden_layers, int hidden_layers_size){

}

Network * create_network(int input_size, int output_size, int hidden_layers, int hidden_layers_size){

    std::vector<Neuron> * input_neurons = new std::vector<Neuron>(input_size);
    std::vector<Neuron> * output_neurons = new std::vector<Neuron>(output_size);
    std::vector<Neuron> * hidden_neurons = new std::vector<Neuron>(hidden_layers*hidden_layers_size);

    Network * network = new Network;
}

Network * load_model(FILE * model){

    int input_size, output_size, hidden_layers, hidden_layers_size;

    fscanf(model, "%d", &input_size);
    fscanf(model, "%d", &output_size);
    fscanf(model, "%d", &hidden_layers);
    fscanf(model, "%d", &hidden_layers_size);

    printf("%d %d %d %d\n", input_size, output_size, hidden_layers, hidden_layers_size);

    Network * network = create_network(input_size, output_size, hidden_layers, hidden_layers_size);
}