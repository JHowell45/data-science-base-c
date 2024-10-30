#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct {
    double *items;
    size_t rows;
    size_t columns;
} matrix_t;

#endif