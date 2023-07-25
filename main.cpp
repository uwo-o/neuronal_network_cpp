#include "menu.hpp"

int main(int argc, char * argv[]){

    Menu * menu = new Menu();

    while(true){
        menu->show();
    }
    
    return 0;
}
