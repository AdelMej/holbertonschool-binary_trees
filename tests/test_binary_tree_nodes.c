#include "../Unity/unity.h"
#include "../binary_trees.h"
#include <string.h>

static binary_tree_t *root = NULL;

void setUp(void) 
{
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

void test_binary_nodes(void)
{
    TEST_ASSERT_EQUAL_INT(2, binary_tree_nodes(root));
}

void test_binary_null(void)
{
    TEST_ASSERT_EQUAL_INT(0, binary_tree_nodes(NULL));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_nodes);
    RUN_TEST(test_binary_null);
    return UNITY_END();
}
