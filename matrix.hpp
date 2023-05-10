#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

/*
Matrix class
 - int rows: Rows quantity
 - int cols: Cols quantity
 - double ** matrix_pointer: Pointer that has the matrix memory direction
*/
class Matrix {
    public:
        int rows;
        int cols;
        std::vector<std::vector<double>> matrix_pointer;
};

#endif