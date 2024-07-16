#include <iostream>
#include <cstdlib>
#include <time.h>

#include "network.h"
#include <unistd.h>

using namespace std;

static const int INPUT_SIZE = 1;
static const int HIDDEN_SIZE = 0;
static const int HIDDEN_LAYERS = 0;
static const int OUTPUT_SIZE = 1;

static const int TRAIN_SIZE = 10;
static const float LEARN_RATE = 0.00001;

float train[TRAIN_SIZE][2] = {
    {0, 32},
    {10, 50},
    {30, 86},
    {50, 122},
    {100, 212},
    {22, 76.1},
    {56, 132.8},
    {89, 192.2},
    {54, 129.2},
    {5, 41}};

float rand_f()
{
    srand(time(0));
    return (float)rand() / RAND_MAX;
}

float cost(float val, float exp)
{
    float diff = val - exp;
    float sq = diff * diff;
    return sq;
}
float error_d(float val, float exp)
{
    return (val - exp) * 2;
}

int main()
{

    float w = rand_f() * 10;
    // wait one second
    sleep(1);

    float b = rand_f() * 10;

    for (size_t i = 0; i < 100000; ++i)
    {
        for (size_t j = 0; j < TRAIN_SIZE; ++j)
        {
            float x = train[j][0];
            float y = w * x + b;
            float exp_x = train[j][1];
            float dx = error_d(y, exp_x);
            w -= LEARN_RATE * dx * x;
            b -= LEARN_RATE * dx;

            cout << "W: " << w << " B: " << b << endl;
        }
    }

    return 0;
}