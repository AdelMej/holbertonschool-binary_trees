#include "../Unity/unity.h"
#include "../binary_trees.h"
#include <string.h>

static binary_tree_t *root = NULL;
static int postorder_values[10];
static size_t postorder_index = 0;

void store_value(int n)
{
    postorder_values[postorder_index++] = n;
}

void setUp(void) 
{
    postorder_index = 0;
    memset(postorder_values, 0, sizeof(postorder_values));

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

void test_binary_tree_postorder(void)
{
    binary_tree_postorder(root, store_value);

   
    TEST_ASSERT_EQUAL_INT(4, postorder_values[0]);
    TEST_ASSERT_EQUAL_INT(2, postorder_values[1]);
    TEST_ASSERT_EQUAL_INT(3, postorder_values[2]);
    TEST_ASSERT_EQUAL_INT(1, postorder_values[3]);

    TEST_ASSERT_EQUAL_UINT32(4, postorder_index);
}

void test_binary_tree_postorder_null(void)
{
    binary_tree_postorder(NULL, store_value);
    TEST_ASSERT_EQUAL_UINT32(0, postorder_index);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_postorder);
    RUN_TEST(test_binary_tree_postorder_null);
    return UNITY_END();
}
