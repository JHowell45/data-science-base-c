#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

vector_t *new_vector(size_t size) {
  vector_t *vec = malloc(sizeof(vector_t));
  vec->size = size;
  vec->items = calloc(vec->size, sizeof(double));
  return vec;
}

vector_t *new_vector_with_default(size_t size, double default_value) {
  vector_t *vec = new_vector(size);
  for (register int i = 0; i < vec->size; i++) {
    vector_insert(vec, i, default_value);
  }
  return vec;
}

vector_t *random_vector(size_t size) {}

void free_vector(vector_t *vec) {
  if (vec->items != NULL) {
    free(vec->items);
  }
  free(vec);
}

void display_vector(vector_t *vec) {
  printf("[");
  for (int i = 0; i < vec->size; i++) {
    if (i == 0) {
      printf("%lf", vec->items[i]);
    } else {
      printf(", %lf", vec->items[i]);
    }
  }
  printf("]\n");
}

double vector_get(vector_t *vec, size_t index) { return vec->items[index]; }

bool vector_insert(vector_t *vec, size_t index, double value) {
  vec->items[index] = value;
}

vector_t *vector_scalar_multiplication(vector_t *vec, double scalar) {
  vector_t *results = new_vector(vec->size);
  cblas_dcopy(vec->size, vec->items, 1, results->items, 1);
  cblas_dscal(vec->size, scalar, results->items, 1);
  return results;
}

double vector_dot_product(vector_t *v1, vector_t *v2) {
    return cblas_ddot(v1->size, v1->items, 1, v2->items, 1);
}