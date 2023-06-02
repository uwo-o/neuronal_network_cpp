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
		neurons.push_back(n);
	}
}

void Network::connector(){
	stack<int> stack;
	int current_id=0;
	for(int i=this->input_size; i>0; i--){
		stack.push(i-1);
	}
	while(!stack.empty()){
		Neuron * input_neuron = this->neurons[stack.top()];
		if(input_neuron->status == -1){
			Link *link = new Link();
			link->input = input_neuron;
			input_neuron->status = 0;
		}
		int next_neuron_id = get_next_first_layer_neuron_id(stack.top());
		int layer_offset = next_neuron_id + current_id;
		if(next_neuron_id >= this->neurons.size() - this->output_size){
			link->output = this->neurons[layer_offset];
			this->neurons[layer_offset]->status = 1;
			current_id+=1;
		}
		if(this->neurons[layer_offset]->status == -1){
			stack.push(layer_offset);
			link.output = this->neurons[layer_offset];
			current_id = 0;
		}else{
			link.output = this->neurons[layer_offset];
			current_id+=1;
		}
		if(this->is_final_layer_neuron(layer_offset)){
			stack.pop();
			input_neuron->status = 1;
			current_id = 0;
		}
	}
}

int Network::get_next_first_layer_neuron_id(int id){
	if(id < this->input_size){
		return this->input_size;
	}else if(id < this->input_size + this->total_hidden_neurons){
		return this->input_size + this->hidden_layers_size;
	}
	int offset_id = id - this->input_size;
	float fractional_part = offset_id % 1;
	float part = (fractional_part/this->hidden_layers) * this->total_hidden_neurons;
	return (int)part + 1;
}

bool Network::is_final_layer_neuron(int id){
	if(id % (this->input_size - 1) == 0){
		return true;
	}
	if(id % (this->neurons.size() - 1) == 0){
		return true;
	}
	for(int i=1; i<=this->hidden_layers; i++){
		int layer_quantity = this->hidden_layers_size * i;
		if(id % (layer_quantity - 1) == 0){
			return true;
		}
	}
	return false;
}
