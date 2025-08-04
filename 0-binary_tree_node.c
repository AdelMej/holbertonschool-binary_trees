#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_node - a function that create a new node
* @parent: the parent of the new node
* @value: the value of the new node
*
* Return: the new node
* NULL if it fails
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;

	return (new);
}
