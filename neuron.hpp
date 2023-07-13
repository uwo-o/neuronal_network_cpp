#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <tuple>
#include <stdlib.h>

class Neuron {
	private:
		double value;
		static int global_id;
		const int id;
		int status;
	protected:
		std::vector<Neuron *> parents_neurons;
		std::vector<std::tuple<double, Neuron *>> children_neurons;
	public:

		// The constructor creates every neuron with random initial values, these values will be changed during the learning process
		Neuron() : id(global_id++), value((double)rand()), status(-1) {};	

		void synapse();

		double apply_activation_function(double x);

		double get_value(){return this->value;};
		int get_status(){return this->status;};
		int get_id(){return this->id;};

		void set_value(double value){this->value = value;};
		void set_status(int status){this->status = status;};
};

#endif
