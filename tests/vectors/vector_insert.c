#include "unity.h"
#include "vector.h"

#define VECTOR_SIZE 3

void setUp(void) {}

void tearDown(void) {}

static void test_values_are_zero_for_created_vector(void) {
  vector_t *vec = new_vector(VECTOR_SIZE);
  for (int i = 0; i < VECTOR_SIZE; i++) {
    TEST_ASSERT_EQUAL_DOUBLE(vector_get(vec, i), 0);
  }
  free_vector(vec);
}

static void test_insert_value_to_vector(void) {
  double val = 5.0;
  vector_t *vec = new_vector(VECTOR_SIZE);
  vector_insert(vec, 0, val);
  TEST_ASSERT_EQUAL_DOUBLE(vector_get(vec, 0), val);
  free_vector(vec);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_values_are_zero_for_created_vector);
  RUN_TEST(test_insert_value_to_vector);
  return UNITY_END();
}