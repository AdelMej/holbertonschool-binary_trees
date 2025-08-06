#include "binary_trees.h"

/**
* binary_tree_nodes - a function that find all the nodes without the leafs
* @tree: the root of the binary_tree
*
* Return: the number of nodes
* 0 if root is a leaf or that it's NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node_numbers = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	node_numbers += binary_tree_nodes(tree->left);
	node_numbers += binary_tree_nodes(tree->right);

	return (node_numbers + 1);
}
