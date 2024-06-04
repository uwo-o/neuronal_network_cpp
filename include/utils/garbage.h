#ifndef GARBAGE_H
#define GARBAGE_H

#include <set>

class Garbage {
    private:
        static std::set<void *> garbage;
    public:
        static void add(void * ptr);
        static void collect();
};

#endif