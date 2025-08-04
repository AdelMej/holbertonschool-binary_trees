#include "../Unity/unity.h"
#include "../binary_trees.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_add_left(void)
{
	binary_tree_t *toTest;

	toTest = binary_tree_node(NULL, 15);
	toTest->left = binary_tree_insert_left(toTest, 45);
	
	TEST_ASSERT_NOT_NULL(toTest->left);
	TEST_ASSERT_EQUAL_INT(toTest->left->n, 45);
	TEST_ASSERT_NOT_NULL(toTest->left->parent);
	TEST_ASSERT_EQUAL_PTR(toTest, toTest->left->parent);
}

void test_add_null(void)
{
	binary_tree_t *toTest;

	toTest = binary_tree_node(NULL, 15);
	toTest->left = binary_tree_insert_left(NULL, 45);
	
	TEST_ASSERT_NULL(toTest->left);
}

void test_with_alreadyexisting_child(void)
{
	binary_tree_t *toTest;

	toTest = binary_tree_node(NULL, 15);
	toTest->left = binary_tree_insert_left(toTest, 55);
	toTest->left = binary_tree_insert_left(toTest, 18);

	TEST_ASSERT_NOT_NULL(toTest->left);
	TEST_ASSERT_EQUAL_INT(toTest->left->n, 18);
	TEST_ASSERT_NOT_NULL(toTest->left->parent);
	TEST_ASSERT_EQUAL_PTR(toTest, toTest->left->parent);
	TEST_ASSERT_NOT_NULL(toTest->left->left);
	TEST_ASSERT_EQUAL_INT(toTest->left->left->n, 55);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_left);
	RUN_TEST(test_add_null);
	RUN_TEST(test_with_alreadyexisting_child);
    return UNITY_END();
}
