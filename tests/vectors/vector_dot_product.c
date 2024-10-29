#include "unity.h"
#include "vector.h"

#include <stdio.h>

#define VECTOR_SIZE 3

void setUp(void) {}

void tearDown(void) {}

static void test_vector_dot_product_basic(void) {
  vector_t *v1 = new_vector(VECTOR_SIZE);
  vector_t *v2 = new_vector(VECTOR_SIZE);

  for (int i = 0; i < v1->size; i++) {
    vector_insert(v1, i, i);
    TEST_ASSERT_EQUAL_DOUBLE(vector_get(v1, i), i);

    vector_insert(v2, i, i);
    TEST_ASSERT_EQUAL_DOUBLE(vector_get(v2, i), i);
  }
  
  double result = vector_dot_product(v1, v2);

  TEST_ASSERT_EQUAL_DOUBLE(result, 5);

  free_vector(v1);
  free_vector(v2);
}

static void test_vector_dot_product_another(void) {
  vector_t *v1 = new_vector(VECTOR_SIZE);
  vector_t *v2 = new_vector(VECTOR_SIZE);

  vector_insert(v1, 0, 2);
  vector_insert(v1, 1, 2);
  vector_insert(v1, 2, 2);

  vector_insert(v2, 0, 5);
  vector_insert(v2, 1, 4);
  vector_insert(v2, 2, 7);
  
  double result = vector_dot_product(v1, v2);

  TEST_ASSERT_EQUAL_DOUBLE(result, 32);

  free_vector(v1);
  free_vector(v2);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_vector_dot_product_basic);
  RUN_TEST(test_vector_dot_product_another);
  return UNITY_END();
}