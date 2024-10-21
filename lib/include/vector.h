#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
  size_t size;
  double *items;
} vector_t;

vector_t *new_vector(size_t size);

#endif