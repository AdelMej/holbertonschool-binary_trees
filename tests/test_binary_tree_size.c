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

void test_binary_tree_size(void)
{
	TEST_ASSERT_EQUAL_INT(4, binary_tree_size(root));
}

void test_null(void)
{
	TEST_ASSERT_EQUAL_INT(0, binary_tree_size(NULL));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_size);
    RUN_TEST(test_null);
    return UNITY_END();
}
