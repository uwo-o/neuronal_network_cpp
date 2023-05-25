#include "network.hpp"

using namespace std;

// Network constructor
Network::Network(int input_size, int output_size, int hidden_layers, int hidden_layers_size){
	this->input_size = input_size;
	this->output_size = output_size;
	this->hidden_layers = hidden_layers;
	this->hidden_layers_size = hidden_layers_size;
	this->total_hidden_neurons = hidden_layers * hidden_layers_size;

	int total_neurons = input_size + output_size + hidden_layers * hidden_layers_size;

	for(int i = 0; i < total_neurons; i++){
		Neuron *n = new Neuron();
		nurons.push_back(n);
	}
}
