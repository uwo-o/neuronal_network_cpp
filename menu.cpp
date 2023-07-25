#include "menu.hpp"
#include "constants.hpp"

Menu::Menu(){
    this->model_loaded = 0;
    this->model_name = NULL;
    this->network = NULL;
}

void Menu::print_menu(){
    std::cout << "-- Options --\n" << std::endl;
    if (this->model_loaded == 0){
        std::cout << "1. Load model" << std::endl;
    }else{
        std::cout << "1. train model" << std::endl;
        std::cout << "2. test model" << std::endl;
        std::cout << "3. Close model" << std::endl;
    }
    std::cout << "0. Exit" << std::endl;
}

void Menu::print_status(){
    std::cout << "Model loaded: " << this->model_loaded  << std::endl;
    std::cout << "Model name: " << (this->model_name ? this->model_name : "null" ) << "\n" << std::endl;
}

void Menu::show(){
    // clean the screen
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Neuronal Network C++.\n" << VERSION_NAME  << ". version: " << VERSION << "\n"<< std::endl;
    this->print_status();
    this->print_menu();
    int selection = this->selection();
    if (this->update_state(selection)){
        this->show();
    }
}

bool Menu::update_state(int selection){
    if (this->model_loaded != 0){
        if (selection == 1){
            std::cout << "Training model..." << std::endl;
            return true;
        }else if (selection == 2){
            std::cout << "Testing model..." << std::endl;
            return true;
        }else if (selection == 3){
            std::cout << "Closing model..." << std::endl;
            return true;
        }
    }else{
        if (selection == 1){
            //this->load_model();
            return true;
        }
    }
    return false;
}

int Menu::selection(){
    std::cout << "\nPlease select an option: ";
    int selection = 0;
    std::cin.get() >> selection;
    if (!selection){
        std::cout << "\nExiting..." << std::endl;
        exit(0);
    }
    return selection;
}