#include "../Unity/unity.h"
#include "../binary_trees.h"

static binary_tree_t *root = NULL;

void setUp(void)
{
    /**
     * Build this tree:
     *         1
     *       /   \
     *      2     3
     *     /
     *    4
     *
     * Leaves = [4, 3] → total = 2
     */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
}

void tearDown(void)
{
    binary_tree_delete(root);
    root = NULL;
}

void test_binary_tree_leaves_count(void)
{
    size_t leaves = binary_tree_leaves(root);
    TEST_ASSERT_EQUAL_UINT(2, leaves);
}

void test_binary_tree_leaves_single_node(void)
{
    binary_tree_t *single = binary_tree_node(NULL, 42);
    TEST_ASSERT_EQUAL_UINT(1, binary_tree_leaves(single));
    binary_tree_delete(single);
}

void test_binary_tree_leaves_null_tree(void)
{
    TEST_ASSERT_EQUAL_UINT(0, binary_tree_leaves(NULL));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_leaves_count);
    RUN_TEST(test_binary_tree_leaves_single_node);
    RUN_TEST(test_binary_tree_leaves_null_tree);
    return UNITY_END();
}