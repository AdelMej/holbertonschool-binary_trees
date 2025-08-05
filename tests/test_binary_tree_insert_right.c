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
	toTest->right = binary_tree_insert_right(toTest, 45);
	
	TEST_ASSERT_NOT_NULL(toTest->right);
	TEST_ASSERT_EQUAL_INT(toTest->right->n, 45);
	TEST_ASSERT_NOT_NULL(toTest->right->parent);
	TEST_ASSERT_EQUAL_PTR(toTest, toTest->right->parent);
}

void test_add_null(void)
{
	binary_tree_t *toTest;

	toTest = binary_tree_node(NULL, 15);
	toTest->left = binary_tree_insert_right(NULL, 45);
	
	TEST_ASSERT_NULL(toTest->left);
}

void test_with_alreadyexisting_child(void)
{
	binary_tree_t *toTest;

	toTest = binary_tree_node(NULL, 15);
	toTest->right = binary_tree_insert_right(toTest, 55);
	toTest->right = binary_tree_insert_right(toTest, 18);

	TEST_ASSERT_NOT_NULL(toTest->right);
	TEST_ASSERT_EQUAL_INT(toTest->right->n, 18);
	TEST_ASSERT_NOT_NULL(toTest->right->parent);
	TEST_ASSERT_EQUAL_PTR(toTest, toTest->right->parent);
	TEST_ASSERT_NOT_NULL(toTest->right->right);
	TEST_ASSERT_EQUAL_INT(toTest->right->right->n, 55);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_left);
	RUN_TEST(test_add_null);
	RUN_TEST(test_with_alreadyexisting_child);
    return UNITY_END();
}
