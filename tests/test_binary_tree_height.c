#include "../Unity/unity.h"
#include "../binary_trees.h"
#include <string.h>

static binary_tree_t *root = NULL;
static int postorder_values[10];
static size_t postorder_index = 0;

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

void test_binary_tree_height(void)
{
    TEST_ASSERT_EQUAL_INT(2, binary_tree_height(root));
}

void test_null(void)
{
	TEST_ASSERT_EQUAL_INT(0, binary_tree_height(NULL));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_height);
    RUN_TEST(test_null);
    return UNITY_END();
}
