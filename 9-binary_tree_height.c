#include "binary_trees.h"

/**
* binary_tree_height - a function that returns the heigh of the binary tree
* @tree: the root of the binary tree
*
* Return: 0 if NULL or a leaf
* maxHeight + 1 recursively
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0, maxHeight = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	maxHeight = left;
	if (left < right)
		maxHeight = right;

	return (maxHeight + 1);
}
