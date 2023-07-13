#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <stack>

#include "neuron.hpp"

class Network {
	private:
		void connector(std::stack <Neuron *> * stack, Neuron * current, int layer);
		Neuron * get_unconnected_neuron(int layer);
		int get_layer(int neuron_id);
		int input_size;
		int output_size;
		int hidden_layers;
		int hidden_layers_size;
		static int total_hidden_neurons;
		std::vector<Neuron *> * input_neurons;
		std::vector<std::vector <Neuron *> *> * hidden_neurons; 
		std::vector<Neuron *> * output_neurons;
	public:
		Network(int input_size, int output_size, int hidden_layers, int hidden_layers_size);

		int get_input_size(){return this->input_size;};
		int get_output_size(){return this->output_size;};
		int get_hidden_layers(){return this->hidden_layers;};
		int get_hidden_layers_size(){return this->hidden_layers_size;};
		int get_total_hidden_neurons(){return this->total_hidden_neurons;};
};

#endif
