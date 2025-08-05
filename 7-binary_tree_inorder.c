#include "binary_trees.h"

/**
* binary_tree_inorder - a function that raverse the tree in order
* @tree: the root of the binary tree
* @func: a pointer to a function to use
*
* Return: always void
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
