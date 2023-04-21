#ifndef MATRIX_H
#define MATRIX_H

/*
Matrix struct
 - int rows: Rows quantity
 - int cols: Cols quantity
 - double ** matrix_pointer: Pointer that has the matrix memory direction
*/
typedef struct Matrix {
    int rows;
    int cols;
    double ** matrix_pointer;
} Matrix;

#endif