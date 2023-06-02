#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <stack>

#include "neuron.hpp"

class Network {
	private:
		void connector();
		int get_next_first_layer_neuron_id(int neuron_id);
		bool is_final_layer_neuron(int neuron_id);
	public:
		Network(int input_size, int output_size, int hidden_layers, int hidden_layers_size);
		int input_size;
		int output_size;
		int hidden_layers;
		int hidden_layers_size;
		static int total_hidden_neurons;
		std::vector<Neuron *> neurons;
};

#endif
