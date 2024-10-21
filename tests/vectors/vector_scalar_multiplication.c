#include "unity.h"
#include "vector.h"

#define VECTOR_SIZE 5

void setUp(void) {}

void tearDown(void) {}

static void test_multiple_vector_with_zero(void) {
  vector_t *vec = new_vector(VECTOR_SIZE);
  free_vector(vec);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_multiple_vector_with_zero);
  return UNITY_END();
}