#include <iostream>
#include <math.h>

#include "menu.h"
#include "network.h"

int main(int argc, char * argv[]){

    Menu * menu = new Menu();
    bool running = true;

    while (running) {
        std::string input = menu->input();

        if (input == "create")
        {
            std::cout << "Creating network" << std::endl;
            Network * network = new Network(0.1, 3, 2, 2, [](double x) { return 1 / (1 + std::exp(-x)); });
            std::cout << "Network created" << std::endl;
            network->set_name("test");
            menu->set_model(network);
            
        }

        if (input == "status") {
            menu->print_status();
        }

        if (input == "describe") {
            menu->get_model()->describe();
        }

        if (input == "fdescribe") {
            menu->get_model()->full_describe();
        }
        

        if (input == "exit") {
            running = false;
        }
    }

    return 0;
}
