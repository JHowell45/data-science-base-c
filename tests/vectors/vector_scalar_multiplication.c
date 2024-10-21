#include "unity.h"
#include "vector.h"

#define VECTOR_SIZE 5

void setUp(void) {}

void tearDown(void) {}

static void test_multiple_vector_with_zero(void) {
  vector_t *vec = new_vector_with_default(VECTOR_SIZE, 1.0);
  for (int i = 0; i < vec->size; i++) {
    TEST_ASSERT_EQUAL_DOUBLE(vector_get(vec, i), 1.0);
  }

  vector_t *results = vector_scalar_multiplication(vec, 0);
  for (int i = 0; i < results->size; i++) {
    {
      TEST_ASSERT_EQUAL_DOUBLE(vector_get(results, i), 0);
    }
  }

  free_vector(vec);
}

static void test_multiple_vector_double(void) {
  vector_t *vec = new_vector_with_default(VECTOR_SIZE, 1.0);
  for (int i = 0; i < vec->size; i++) {
    TEST_ASSERT_EQUAL_DOUBLE(vector_get(vec, i), 1.0);
  }

  vector_t *results = vector_scalar_multiplication(vec, 2);
  for (int i = 0; i < results->size; i++) {
    {
      TEST_ASSERT_EQUAL_DOUBLE(vector_get(results, i), vector_get(vec, i) * 2);
    }
  }

  free_vector(vec);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_multiple_vector_with_zero);
  RUN_TEST(test_multiple_vector_double);
  return UNITY_END();
}