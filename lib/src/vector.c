#include "vector.h"

#include <stdlib.h>

vector_t *new_vector(size_t size) {
  vector_t *vec = malloc(sizeof(vector_t));
  vec->size = size;
  vec->items = calloc(vec->size, sizeof(double));
  return vec;
}

vector_t *random_vector(size_t size) {}

void free_vector(vector_t *vec) {
  if (vec->items != NULL) {
    free(vec->items);
  }
  free(vec);
}

void display_vector(vector_t *vec) {}

bool vector_insert(vector_t *vec, size_t index, double value) {}

vector_t *vector_scalar_multiplication(vector_t *vec, double scalar) {}