#include "network.hpp"

using namespace std;

// Network constructor
Network::Network(int input_size, int output_size, int hidden_layers, int hidden_layers_size){
	this->input_size = input_size;
	this->output_size = output_size;
	this->hidden_layers = hidden_layers;
	this->hidden_layers_size = hidden_layers_size;

	for(int i = 0; i < this->input_size; i++){
		Neuron * neuron = new Neuron;
		this->input_neurons.push_back(neuron);
	}

	for(int i = 0; i < this->hidden_layers*this->hidden_layers_size; i++){
		Neuron * neuron = new Neuron;
		this->hidden_neurons.push_back(neuron);
	}

	for(int i = 0; i < this->output_size; i++){
		Neuron * neuron = new Neuron;
		this->output_neurons.push_back(neuron);
	}
}
