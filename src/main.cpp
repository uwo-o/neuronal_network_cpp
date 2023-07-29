#include "menu.hpp"
#include "network.hpp"

int main(int argc, char * argv[]){

    /*
    Menu * menu = new Menu();

    while(true){
        std::string input = menu->input();
    }*/

    Network * network = new Network(2, 1, 1, 2);

    return 0;
}
