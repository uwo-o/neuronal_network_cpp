#include <stdio.h>

#include "matrix.h"
#include "neurone.h"
#include "transform.h"

int main(int argc, char * argv[]){

    if(argc==1){
        printf("Please insert a neuron model to load\n");
    }

    FILE *ptr;
    ptr = fopen(argv[1], "r");

    return 0;
}