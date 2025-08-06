#include "binary_trees.h"

/**
* binary_tree_sibling - return the sibling of a node
* @node: the node to test
*
* Return: the pointer to the sibling node
* NULL if no sibling are found or node is NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
