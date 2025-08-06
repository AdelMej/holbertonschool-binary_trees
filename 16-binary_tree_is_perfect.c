#include "binary_trees.h"

static size_t binary_tree_height_helper(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect-  checks if a binary tree is perfect
 * @tree: the root of the binary tree
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
	{
		return (0);
	}

	left = binary_tree_height_helper(tree->left);
	right = binary_tree_height_helper(tree->right);

	if (left != right)
	{
	return (0);
	}

	if (left == 0 && right == 0)
	{
	return (1);
	}

return (binary_tree_is_perfect(tree->left) &&
binary_tree_is_perfect(tree->right));

}

/**
* binary_tree_height - a function that returns the heigh of the binary tree
* @tree: the root of the binary tree
*
* Return: 0 if NULL or a leaf
* maxHeight + 1 recursively
*/
static size_t binary_tree_height_helper(const binary_tree_t *tree)

{
	size_t left = 0, right = 0, maxHeight = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);


	left = binary_tree_height_helper(tree->left);
	right = binary_tree_height_helper(tree->right);

	maxHeight = left;
	if (left < right)
		maxHeight = right;

	return (maxHeight + 1);
}
