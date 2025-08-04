#include "../Unity/unity.h"
#include "../binary_trees.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_deleting_big_tree (void)
{
	binary_tree_t *toTest = NULL;

	toTest = binary_tree_node(toTest, 45);
	toTest->left = binary_tree_node(toTest->left, 45);
	toTest->right = binary_tree_node(toTest->right, 45);
	binary_tree_delete(toTest);

	TEST_ASSERT_NULL(toTest);
}

void test_give_null(void)
{
	binary_tree_t *toTest = NULL;

	binary_tree_delete(toTest);
	TEST_ASSERT_NULL(toTest);
}

int main(void)
{
    UNITY_BEGIN();
	RUN_TEST(test_deleting_big_tree);
	RUN_TEST(test_give_null);
    return UNITY_END();
}
