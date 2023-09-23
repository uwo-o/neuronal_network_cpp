#include "includes/menu.hpp"
#include "includes/constants.hpp"

Menu::Menu(){
    this->model_loaded = 0;
    this->model_name = NULL;
    this->network = NULL;
    std::cout << "\033[2J\033[1;1H"; //clean screen
    std::cout << "Neuronal Network C++.\n" << VERSION_NAME  << ". version: " << VERSION << "\n"<< std::endl;
}

void Menu::print_status(){
    std::cout << "Model loaded: " << this->model_loaded  << std::endl;
    std::cout << "Model name: " << (this->model_name ? this->model_name : "null" ) << "\n" << std::endl;
}

std::string Menu::input(){
    std::string input;
    std::cout << "<nnc "<<VERSION<<"> "<<VERSION_NAME<<"@"<<(this->model_name ? this->model_name : "no-model")<<": ";
    getline(std::cin, input);
    return input;
}