#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <tuple>
#include <stdlib.h>

class Neuron {
	private:
		double value;
		int id;
		int status;
	protected:
		static int global_id;
		std::vector<Neuron *> parents_neurons;
		std::vector<std::tuple<double, Neuron *>> children_neurons;
	public:

		Neuron();

		void synapse();

		double apply_activation_function(double x);

		double get_value(){return this->value;};
		int get_status(){return this->status;};
		int get_id(){return this->id;};
		std::vector<Neuron *> get_parents_neurons(){return this->parents_neurons;};
		std::vector<std::tuple<double, Neuron *>> get_children_neurons(){return this->children_neurons;};

		void set_value(double value){this->value = value;};
		void set_status(int status){this->status = status;};
		void push_child(std::tuple<double, Neuron *> child){this->children_neurons.push_back(child);};
		void push_parent(Neuron * parent){this->parents_neurons.push_back(parent);};
};

#endif
