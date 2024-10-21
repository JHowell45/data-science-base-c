#include "vector.h"

#include <stdlib.h>

vector_t *new_vector(size_t size) {
  vector_t *vec = malloc(sizeof(vector_t));
  vec->size = size;
  vec->items = calloc(vec->size, sizeof(double));
  return vec;
}