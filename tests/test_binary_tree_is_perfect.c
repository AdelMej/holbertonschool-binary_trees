#include "../Unity/unity.h"
#include "../binary_trees.h"

static binary_tree_t *root = NULL;

void setUp(void)
{
    root = NULL;
}

void tearDown(void)
{
    binary_tree_delete(root);
    root = NULL;
}

void test_perfect_tree(void)
{
    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->left->right = binary_tree_node(root->left, 5);
    root->right->left = binary_tree_node(root->right, 6);
    root->right->right = binary_tree_node(root->right, 7);

    TEST_ASSERT_TRUE(binary_tree_is_perfect(root));
}

void test_incomplete_tree_missing_one_leaf(void)
{
    /*
              1
             / \
            2   3
           /
          4
    */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);

    TEST_ASSERT_FALSE(binary_tree_is_perfect(root));
}

void test_null_tree(void)
{
    TEST_ASSERT_FALSE(binary_tree_is_perfect(NULL));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_perfect_tree);
    RUN_TEST(test_incomplete_tree_missing_one_leaf);
    RUN_TEST(test_null_tree);
    return UNITY_END();
}
