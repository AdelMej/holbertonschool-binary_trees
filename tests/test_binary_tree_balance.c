#include "../Unity/unity.h"
#include "../binary_trees.h"

static binary_tree_t *root = NULL;

void setUp(void)
{
    /*
             98
            /  \
          12    128
         /
       54
    */
    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->left = binary_tree_node(root->left, 54);
}

void tearDown(void)
{
    binary_tree_delete(root);
    root = NULL;
}

void test_balance_of_root(void)
{
    int balance = binary_tree_balance(root);
    TEST_ASSERT_EQUAL_INT(1, balance);  // Left subtree is taller
}

void test_balance_of_left_child(void)
{
    int balance = binary_tree_balance(root->left);
    TEST_ASSERT_EQUAL_INT(1, balance);  // 54 is on the left
}

void test_balance_of_right_child(void)
{
    int balance = binary_tree_balance(root->right);
    TEST_ASSERT_EQUAL_INT(0, balance);  // 128 has no children
}

void test_balance_of_leaf(void)
{
    int balance = binary_tree_balance(root->left->left);
    TEST_ASSERT_EQUAL_INT(0, balance);  // 54 is a leaf
}

void test_balance_null(void)
{
    int balance = binary_tree_balance(NULL);
    TEST_ASSERT_EQUAL_INT(0, balance);  // NULL should return 0
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_balance_of_root);
    RUN_TEST(test_balance_of_left_child);
    RUN_TEST(test_balance_of_right_child);
    RUN_TEST(test_balance_of_leaf);
    RUN_TEST(test_balance_null);
    return UNITY_END();
}

