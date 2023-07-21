#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "neuron.hpp"
#include "network.hpp"
#include "menu.hpp"

int main(int argc, char * argv[]){

    Network * network = NULL;

    while(true){
        std::cout << "NNC++ started\nModel loaded:\n"<< std::endl;
        if(!network){
            std::cout << "No model loaded, please select one optionn"<< std::endl;
            // GO TO NO MODEL OPTIONS IN MENU
        }
        // GO TO MODEL OPTIONS IN MENU
    }
    
    return 0;
}
