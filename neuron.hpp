#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

typedef class Link Link;

class Neuron {
	private:
		double value;
		static int global_id;
		const int id;
	protected:
		std::vector<Link *> parents_neurons;
		std::vector<Link *> children_neurons;
		double bias;
	public:
		Neuron() : id(global_id++), value(0), bias(0) {};	
		void synapse();
		double apply_activation_function(double x);
		double get_bias(){return bias;};
		double get_value(){return value;};
		void set_value(double value){this->value = value;};
		void set_bias(double bias){this->bias = bias;};
};

class Link {
	public:
		Link(Neuron * input, Neuron * output, double weight){
			this->input = input;
			this->output = output;
			this->weight = weight;
		};
		Neuron * input;
		Neuron * output;
		double weight;
};

#endif
