#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "neuron.hpp"
#include "network.hpp"
#include "menu.hpp"
#include "constants.hpp"

int main(int argc, char * argv[]){

    Menu * menu = new Menu();

    while(true){
        menu->show();
    }
    
    return 0;
}
