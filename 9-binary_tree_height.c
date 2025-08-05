#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0, maxHeight = 0;

	if (tree == NULL)
		return (0);

	if(binary_tree_is_leaf(tree))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	maxHeight = left;
	if (left < right)
		maxHeight = right;

	return (maxHeight + 1);
}
