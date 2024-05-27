#include "menu.h"
#include "constants.h"

Menu::Menu(){
    std::cout << "\033[2J\033[1;1H"; //clean screen
    std::cout << "Neuronal Network C++.\n" << VERSION_NAME  << ". version: " << VERSION << "\n"<< std::endl;
    this->model = nullptr;
}

void Menu::set_model(Network * model){
    this->model = model;
}

Network * Menu::get_model(){
    return this->model;
}

void Menu::print_status(){
    std::cout << "Model name: " << (this->model != nullptr ? this->model->get_name() : "null" ) << "\n" << std::endl;
}

std::string Menu::input(){
    std::string input;
    std::cout << "<nnc "<<VERSION<<"> "<<VERSION_NAME<<"@"<<(this->model ? this->model->get_name() : "no-model")<<": ";
    getline(std::cin, input);
    return input;
}