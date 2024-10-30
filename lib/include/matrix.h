#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct {
    double *items;
    size_t rows;
    size_t columns;
} matrix_t;

matrix_t *new_matrix(size_t rows, size_t columns);
matrix_t *new_matrix_with_default(size_t rows, size_t columns, double default_value);
matrix_t *random_matrix(size_t rows, size_t columns);
void free_matrix(matrix_t *m);
void display_matrix(matrix_t *m);

double matrix_get(matrix_t *m, size_t x, size_t y);

bool matrix_insert(matrix_t *m, size_t x, size_t y, double value);

#endif