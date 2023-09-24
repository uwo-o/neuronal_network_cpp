#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <regex>

class Menu{
    private:
        int model_loaded;
        char *model_name;
    public:
        Menu();
        void print_status();
        std::string input();
};

#endif