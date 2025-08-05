#include "binary_trees.h"

/**
* binary_tree_is_root - function that says if a binary tree is root or not
* @node: the node to test
*
* Return: 0 if it's not a root
* otherwise return 1
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}
