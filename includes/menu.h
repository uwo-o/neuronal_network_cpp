#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <regex>

#include "network.h"
class Menu{
    private:
        Network * model;
        
    public:
        Menu();
        void print_status();
        std::string input();
        void set_model(Network * model);
        Network * get_model();
};

#endif