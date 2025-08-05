#include "../Unity/unity.h"
#include "../binary_trees.h"

static binary_tree_t *leaf;

void setUp(void) 
{
    leaf = binary_tree_node(NULL, 54);
    TEST_ASSERT_NOT_NULL(leaf);
    binary_tree_insert_right(leaf, 5);
    TEST_ASSERT_NOT_NULL(leaf->right);
    binary_tree_insert_left(leaf, 4);
    TEST_ASSERT_NOT_NULL(leaf->left);
    binary_tree_insert_left(leaf->left, 6);
    TEST_ASSERT_NOT_NULL(leaf->left->left);
}

void tearDown(void) 
{
    binary_tree_delete(leaf);
}

void test_leaf(void)
{
	TEST_ASSERT_FALSE(binary_tree_is_leaf(leaf));
    TEST_ASSERT_TRUE(binary_tree_is_leaf(leaf->right));
    TEST_ASSERT_FALSE(binary_tree_is_leaf(leaf->left));
    TEST_ASSERT_TRUE(binary_tree_is_leaf(leaf->left->left));
}
void test_nul_leaf (void)
{
    TEST_ASSERT_FALSE(binary_tree_is_leaf(NULL));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_leaf);
    RUN_TEST(test_nul_leaf);
    return UNITY_END();
}
