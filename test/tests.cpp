#include "gtest/gtest.h"
#include "algorithms/feedforward.h"
#include "layer.h"
#include "math/vector.h"
#include "math/matrix.h"

TEST (MATH, Test_1) {

    double data[3] = {1, 2, 3};
    Vector *vector = new Vector(3, data);

    EXPECT_EQ(vector->get_size(), 3);
    EXPECT_EQ(vector->get(0), 1);
    EXPECT_EQ(vector->get(1), 2);
    EXPECT_EQ(vector->get(2), 3);

    delete vector;
}