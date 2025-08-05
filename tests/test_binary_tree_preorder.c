#include "../Unity/unity.h"
#include "../binary_trees.h"
#include <string.h>

static binary_tree_t *root = NULL;
static int preorder_values[10];
static size_t preorder_index = 0;

void store_value(int n)
{
    preorder_values[preorder_index++] = n;
}

void setUp(void) 
{
    preorder_index = 0;
    memset(preorder_values, 0, sizeof(preorder_values));

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

void test_binary_tree_preorder(void)
{
    binary_tree_preorder(root, store_value);

   
    TEST_ASSERT_EQUAL_INT(1, preorder_values[0]);
    TEST_ASSERT_EQUAL_INT(2, preorder_values[1]);
    TEST_ASSERT_EQUAL_INT(4, preorder_values[2]);
    TEST_ASSERT_EQUAL_INT(3, preorder_values[3]);

    TEST_ASSERT_EQUAL_UINT32(4, preorder_index);
}

void test_binary_tree_preorder_null(void)
{
    binary_tree_preorder(NULL, store_value);
    TEST_ASSERT_EQUAL_UINT32(0, preorder_index);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_preorder);
    RUN_TEST(test_binary_tree_preorder_null);
    return UNITY_END();
}
