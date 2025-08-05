#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_delete - a function to delete a given tree recusrivly
* @tree: a tree to delete
*
* Return: void
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* delete left node */
	binary_tree_delete(tree->left);
	/* delete right node */
	binary_tree_delete(tree->right);
	free(tree);
}
