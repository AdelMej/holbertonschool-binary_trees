#include "../Unity/unity.h"
#include "../binary_trees.h"

static binary_tree_t *root = NULL;
static binary_tree_t *node_l = NULL;
static binary_tree_t *node_r = NULL;
static binary_tree_t *node_ll = NULL;

void setUp(void)
{
    /**
     * Build the following tree:
     *         1
     *       /   \
     *      2     3
     *     /
     *    4
     */
    root = binary_tree_node(NULL, 1);         // depth 0
    node_l = binary_tree_node(root, 2);       // depth 1
    node_r = binary_tree_node(root, 3);       // depth 1
    root->left = node_l;
    root->right = node_r;

    node_ll = binary_tree_node(node_l, 4);    // depth 2
    node_l->left = node_ll;
}

void tearDown(void)
{
    binary_tree_delete(root);
    root = NULL;
    node_l = node_r = node_ll = NULL;
}

void test_binary_tree_depth_values(void)
{
    TEST_ASSERT_EQUAL_UINT(0, binary_tree_depth(root));
    TEST_ASSERT_EQUAL_UINT(1, binary_tree_depth(node_l));
    TEST_ASSERT_EQUAL_UINT(1, binary_tree_depth(node_r));
    TEST_ASSERT_EQUAL_UINT(2, binary_tree_depth(node_ll));
}

void test_binary_tree_depth_null(void)
{
    TEST_ASSERT_EQUAL_UINT(0, binary_tree_depth(NULL));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_depth_values);
    RUN_TEST(test_binary_tree_depth_null);
    return UNITY_END();
}
