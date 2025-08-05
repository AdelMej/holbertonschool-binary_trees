#include "binary_trees.h"

/**
* binary_tree_is_full - a function that verifies if a tree is full
* @tree: the root of the tree
*
* Return: 1 if it's full, 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
