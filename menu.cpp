#include "menu.hpp"

/*

CONVERT TO C++

int options_check(int argc, char * argv){

    for(int i=0; i<argc; i++){

    }
}

void options (int argc,char * argv){

    int error = options_check(argc, argv);

    if(error){
        printf("[Syntax Error] Error in option '");
        printf(argv[error]);
        printf("doesn't exist. You can use the following options:\n");
        for(int i=0; i<OPTIONS_QUANTITY; i++){
            printf(" - ");
            printf(OPTIONS[OPTIONS_QUANTITY]);
        }
    }

    switch(argv[1]){
        case '-l': load_model(argv[2]); break;
    }
}
*/