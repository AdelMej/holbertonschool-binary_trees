#include "../Unity/unity.h"
#include "../binary_trees.h"

static binary_tree_t *root;
static int array[4];
static unsigned int idx;

void testing(int a)
{
	array[idx++] = a;
}

void setUp(void) {
	idx = 0;
	root = binary_tree_node(NULL, 18);
	TEST_ASSERT_NOT_NULL(root);
	binary_tree_insert_left(root, 15);
	TEST_ASSERT_NOT_NULL(root->left);
	binary_tree_insert_right(root, 45);
	TEST_ASSERT_NOT_NULL(root->right);
	binary_tree_insert_left(root->left, 14);
	TEST_ASSERT_NOT_NULL(root->left->left);
}

void tearDown(void) {
	binary_tree_delete(root);
}


void test_traversal_inorder(void)
{
	binary_tree_inorder(root, testing);

	int expected[4] = {14, 15, 18, 45};
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, idx);
}

void test_null(void)
{
	binary_tree_inorder(NULL, testing);
	binary_tree_inorder(root, NULL);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_traversal_inorder);
	RUN_TEST(test_null);
    return UNITY_END();
}
