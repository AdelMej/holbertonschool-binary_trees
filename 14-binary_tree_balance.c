#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the node to measure the  balance factor.
 * Return: left or right.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
	{
		return (0);
	}

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (left - right);
}

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
