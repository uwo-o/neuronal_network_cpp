#include "menu.hpp"

array<tuple<string, string>, 2> OPTIONS = {
    make_tuple("-l", "[load] With this option you can load a model in memory, you must have to insert a model name inside a text file (.txt)"),
    make_tuple("-h", "[help] With this option you will get a program description and help, you can insert an option to get a description")
};

bool options_check(int argc, vector<string> args){

    for(int i=0; i<OPTIONS.size(); i++){
        if(args[1] == get<0>(OPTIONS[i])){
            return true;
        }
    }

    return false;
}

void options (int argc, vector<string> args){

    if(!options_check(argc, args)){
        cout << "[Syntax Error] Error in option '" << args[1] << "' doesn't exist. You can use the following options:" << endl;
        for(int i=0; i<OPTIONS.size(); i++){
            cout << get<0>(OPTIONS[i]) << " - " << get<1>(OPTIONS[i]) << endl;
        }
        return;
    }

    for(int i=0; i<OPTIONS.size(); i++){
        if(args[1] == get<0>(OPTIONS[i])){
            cout << get<1>(OPTIONS[i]) << endl;
            return;
        }
    }

    return;
}