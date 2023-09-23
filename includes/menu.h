#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <regex>

#include "network.hpp"

class Menu{
    private:
        int model_loaded;
        char *model_name;
        Network *network;
    public:
        Menu();
        void print_status();
        std::string input();
};

#endif