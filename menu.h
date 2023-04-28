#ifndef MENU_H
#define MENU_H

#include <stdio.h>

#include "matrix.h"
#include "network.h"

int OPTIONS_QUANTITY = 2;

char * OPTIONS[] = {'-l', '-h'};

char * OPTIONS_DESCRIPTION[] = {
    "[load] With this option you can load a model in memory, you must have to insert a model name inside a text file (.txt)",
    "[help] With this option you will get a program description and help, you can insert an option to get a description"
};

Matrix * laod_model(FILE * ptr);

#endif