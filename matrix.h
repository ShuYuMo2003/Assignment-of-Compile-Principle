#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <assert.h>

typedef struct {
    int rows, columns;
    double *data;
} Matrix;

double * get_ele(Matrix * mat, int i, int j);

#endif // MATRIX_H