#include "utils/garbage.h"
#include <malloc.h>

std::set<void *> Garbage::garbage;

void Garbage::add(void * ptr) {
    garbage.insert(ptr);
}

void Garbage::collect() {
    for (auto ptr : garbage) {
        free(ptr);
    }
    garbage.clear();
}