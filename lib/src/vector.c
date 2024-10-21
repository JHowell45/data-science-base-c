#include "vector.h"

#include <stdio.h>
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

bool vector_insert(vector_t *vec, size_t index, double value) {}

vector_t *vector_scalar_multiplication(vector_t *vec, double scalar) {}