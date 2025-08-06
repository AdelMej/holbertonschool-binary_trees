#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t total = 0;

	if (tree == NULL)
		return (0);

	total += binary_tree_size(tree->left);
	total += binary_tree_size(tree->right);

	return (total + 1);
}
