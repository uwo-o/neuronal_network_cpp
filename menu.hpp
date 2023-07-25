#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "network.hpp"

class Menu{
    private:
        int model_loaded;
        char *model_name;
        Network *network;
    public:
        Menu();
        void print_menu();
        void load_model();
        void print_status();
        void show();
        bool update_state(int);
        int selection();
};

#endif