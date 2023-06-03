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
		Neuron() : id(global_id++), value(0), bias(0), status(-1) {};	
		void synapse();
		int status;
		double apply_activation_function(double x);
		double get_bias(){return bias;};
		double get_value(){return value;};
		void set_value(double value){this->value = value;};
		void set_bias(double bias){this->bias = bias;};
};

class Link {
	private:
		Neuron * input;
		Neuron * output;
		double weight;
	public:
		Link();
		void set_input(Neuron * neuron){this->input = neuron;};
		void set_output(Neuron * neuron){this->input = neuron;};
		void set_weight(double weight){this->weight = weight;};
		
		double get_weight(){return this->weight;};
};

#endif
