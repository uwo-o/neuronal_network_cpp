#include "neuron.hpp"

int Neuron::global_id = 0;

Neuron::Neuron(){
    this->id = Neuron::global_id++;
    this->status = -1;
    this->value = (double)rand();
}