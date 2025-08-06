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

void tearDown(void) {
	binary_tree_delete(root);
	root = NULL;
}

void test_is_sibling_left(void) {
	binary_tree_print(root);
	TEST_ASSERT_NOT_NULL(binary_tree_sibling(root->left->left));
}

void test_is_silbing_right()
{
	binary_tree_print(root);
	TEST_ASSERT_NOT_NULL(binary_tree_sibling(root->right->right));
}

void test_is_misisng_sibling_left()
{
	binary_tree_delete(root->right);
	root->right = NULL;
	binary_tree_print(root);
	TEST_ASSERT_NULL(binary_tree_sibling(root->left));
}

void test_is_misisng_sibling_right()
{
	binary_tree_delete(root->left);
	root->left = NULL;
	binary_tree_print(root);
	TEST_ASSERT_NULL(binary_tree_sibling(root->right));

}

void test_is_null(void)
{
	TEST_ASSERT_NULL(binary_tree_sibling(NULL));
}

void test_missing_parent(void)
{
	TEST_ASSERT_NULL(binary_tree_sibling(root));
}

void test_single_node(void)
{
	binary_tree_delete(root);
	root = binary_tree_node(NULL, 1);
	binary_tree_print(root);
	TEST_ASSERT_NULL(binary_tree_sibling(root));
}
int main(void) {
    UNITY_BEGIN();
	RUN_TEST(test_is_sibling_left);
	RUN_TEST(test_is_silbing_right);
    RUN_TEST(test_is_misisng_sibling_left);
	RUN_TEST(test_is_misisng_sibling_right);
	RUN_TEST(test_is_null);
	RUN_TEST(test_missing_parent);
	RUN_TEST(test_single_node);
    return UNITY_END();
}
