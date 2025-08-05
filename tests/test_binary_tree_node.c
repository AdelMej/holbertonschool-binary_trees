#include "../Unity/unity.h"
#include "../binary_trees.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_new_node(void)
{
	binary_tree_t *toTest, *parentTest;

	toTest = binary_tree_node(NULL, 15);
	parentTest = binary_tree_node(toTest, 254);

	TEST_ASSERT_EQUAL_INT(toTest->n, 15);
	TEST_ASSERT_NULL(toTest->left);
	TEST_ASSERT_NULL(toTest->right);
	TEST_ASSERT_NULL(toTest->parent);

	TEST_ASSERT_EQUAL_INT(parentTest->n, 254);
	TEST_ASSERT_NULL(parentTest->left);
	TEST_ASSERT_NULL(parentTest->right);
	TEST_ASSERT_NOT_NULL(parentTest->parent);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_new_node);
    return UNITY_END();
}
