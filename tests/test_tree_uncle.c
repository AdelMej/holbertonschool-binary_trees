#include "../Unity/unity.h"
#include "../binary_trees.h"

static binary_tree_t *root;

void setUp(void) 
{
	root = binary_tree_node(NULL, 1);
	TEST_ASSERT_NOT_NULL(root);
	binary_tree_insert_left(root, 2);
	TEST_ASSERT_NOT_NULL(root->left);
	binary_tree_insert_right(root, 3);
	TEST_ASSERT_NOT_NULL(root->right);
	binary_tree_insert_left(root->right, 4);
	TEST_ASSERT_NOT_NULL(root->right->left);
	binary_tree_insert_right(root->right, 5);
	TEST_ASSERT_NOT_NULL(root->right->right);
	binary_tree_insert_left(root->left, 6);
	TEST_ASSERT_NOT_NULL(root->left->left);
	binary_tree_insert_right(root->left, 7);
	TEST_ASSERT_NOT_NULL(root->left->right);
}

void tearDown(void) 
{
    binary_tree_delete(root);
	root = NULL;
}

void is_uncle_left(void)
{
	binary_tree_print(root);
	TEST_ASSERT_NOT_NULL(binary_tree_uncle(root->left->left));
	TEST_ASSERT_NOT_NULL(binary_tree_uncle(root->left->right));
}
void is_uncle_right(void)
{
	binary_tree_print(root);
	TEST_ASSERT_NOT_NULL(binary_tree_uncle(root->right->left));
	TEST_ASSERT_NOT_NULL(binary_tree_uncle(root->right->right));
}

void test_missing_left(void)
{
	binary_tree_print(root);
	TEST_ASSERT_NULL(binary_tree_uncle(root->left));
}

void test_missing_right(void)
{
	binary_tree_print(root);
	TEST_ASSERT_NULL(binary_tree_uncle(root->right));
}

void test_single_node(void)
{
	binary_tree_delete(root);
	root = NULL;
	root = binary_tree_node(NULL, 1);
	TEST_ASSERT_NOT_NULL(root);
	binary_tree_print(root);
	TEST_ASSERT_NULL(binary_tree_uncle(root));
}

void test_nul(void)
{
	TEST_ASSERT_NULL(binary_tree_uncle(NULL));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(is_uncle_left);
	RUN_TEST(is_uncle_right);
	RUN_TEST(test_missing_left);
	RUN_TEST(test_missing_right);
	RUN_TEST(test_single_node);
	RUN_TEST(test_nul);
    return UNITY_END();
}
