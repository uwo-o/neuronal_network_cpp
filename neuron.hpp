#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

class Neuron {
	private:
		double value, bias;
		static int global_id;
		const int id;
		int status;
	protected:
		std::vector<Neuron *> parents_neurons;
		std::vector<Neuron *> children_neurons;
	public:

		// The constructor creates every neuron with random initial values, these values will be changed during the learning process
		Neuron() : id(global_id++), value((double)rand()), bias((double)rand()), status(-1) {};	
		
		void synapse();

		double apply_activation_function(double x);

		double get_bias(){return bias;};
		double get_value(){return value;};
		int get_status(){return status;};
		int get_id(){return id;};

		void set_value(double value){this->value = value;};
		void set_bias(double bias){this->bias = bias;};
		void set_status(int status){this->status = status;};
};

#endif
