#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "matrix.hpp"
#include "neuron.hpp"
#include "transform.hpp"
#include "menu.hpp"

using namespace std;

int main(int argc, char * argv[]){

    vector<string> args = vector<string>(argv, argv+argc);

    if(args.size() == 1){
        cout << "Error: You must insert an option" << endl;
        return 0;
    }

    options(argc, args);
    
    return 0;
}