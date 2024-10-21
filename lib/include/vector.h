#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  size_t size;
  double *items;
} vector_t;

vector_t *new_vector(size_t size);
vector_t *new_vector_with_default(size_t size, double default_value);
vector_t *random_vector(size_t size);
void free_vector(vector_t *vec);
void display_vector(vector_t *vec);

double vector_get(vector_t *vec, size_t index);

bool vector_insert(vector_t *vec, size_t index, double value);

vector_t *vector_scalar_multiplication(vector_t *vec, double scalar);
double vector_dot_product(vector_t *v1, vector_t *v2, double theta);
double vector_cross_product(vector_t *v1, vector_t *v2);

#endif