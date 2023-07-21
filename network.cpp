#include "network.hpp"

// Network constructor
Network::Network(int input_size, int output_size, int hidden_layers, int hidden_layers_size){
	this->input_size = input_size;
	this->output_size = output_size;
	this->hidden_layers = hidden_layers;
	this->hidden_layers_size = hidden_layers_size;
	this->total_hidden_neurons = hidden_layers * hidden_layers_size;

	int total_neurons = input_size + output_size + hidden_layers * hidden_layers_size;

	this->input_neurons = new std::vector<Neuron *>();
	this->hidden_neurons = new std::vector<std::vector<Neuron *> *>();
	this->output_neurons = new std::vector<Neuron *>();

	for(int i=0; i<this->input_size; i++){
		Neuron * neuron = new Neuron();
		this->input_neurons->push_back(neuron);
	}

	std::vector<Neuron *> * layer = new std::vector<Neuron *>();
	for(int i=0; i<this->total_hidden_neurons; i++){
		if(i % this->hidden_layers_size == 0){
			this->hidden_neurons->push_back(layer);
			layer = new std::vector<Neuron *>();
		}
		layer->push_back(new Neuron());
	}

	for(int i=0; i<this->output_size; i++){
		Neuron * neuron = new Neuron();
		this->output_neurons->push_back(neuron);
	}

	this->connector(new std::stack<Neuron *>(), this->input_neurons->front(), 0);
}

Neuron * Network::get_unconnected_neuron(int layer){
	if(layer == 0){
		for(int i=0; i<this->input_neurons->size(); i++){
			if(this->input_neurons->at(i)->get_status() == -1){
				return this->input_neurons->at(i);
			}
		}
	}
	else if(layer < this->hidden_layers){
		for(int i=0; i<this->hidden_layers_size; i++){
			if(this->hidden_neurons->at(layer-1)->at(i)->get_status() == -1){
				return this->hidden_neurons->at(layer-1)->at(i);
			}
		}
	}
	else if(layer == this->hidden_layers){
		for(int i=0; i<this->output_neurons->size(); i++){
			if(this->output_neurons->at(i)->get_status() == -1){
				return this->output_neurons->at(i);
			}
		}
	}
	return NULL;
}

int Network::get_layer(int neuron_id){
	// use math formulas to return the layer
	if (neuron_id < this->input_size){
		return 0;
	}
	else if (neuron_id < this->input_size + this->total_hidden_neurons){
		return 1 + (neuron_id - this->input_size) / this->hidden_layers_size;
	}
	else{
		return this->hidden_layers + 1;
	}
}

void Network::connector(std::stack <Neuron *> * stack, Neuron * current, int layer){
	if(current->get_status() == -1){
		current->set_status(0);
		stack->push(current);
	}
	Neuron * next = this->get_unconnected_neuron(layer+1);
	if(next != NULL){
		current->push_child(std::make_tuple((double)rand(), next));
		next->push_parent(current);
		this->connector(stack, next, layer+1);
	}
	else{
		current->set_status(1);
		stack->pop();
		if(!stack->empty()){
			this->connector(stack, stack->top(), layer-1);
		}
		else{
			delete stack;
		}
	}
}