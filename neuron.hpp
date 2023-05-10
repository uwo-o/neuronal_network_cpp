#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

/*
Neurone class
- int childrens_quantity: The children's array size 
- Neurone * childrens: Pointer that has the Neuone array
- std::vector<Neuron*> parents: Vector of parent neuron pointers
- std::vector<Neuron*> childrens: Vector of child neuron pointers
- int layer_id: The layer deeps number
*/
class Neuron {
    public:
        int parents_quantity;
        int childrens_quantity;
        std::vector<Neuron*> parents;
        std::vector<Neuron*> childrens;
        double value;
        int layer_id;
};

#endif