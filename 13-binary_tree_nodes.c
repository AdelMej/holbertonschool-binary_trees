#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node_numbers = 0;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	node_numbers += binary_tree_nodes(tree->left);
	node_numbers += binary_tree_nodes(tree->right);

	return (node_numbers + 1);
}
