#include "binary_trees.h"

/**
* binary_tree_insert_left - a function to insert a new node in the left
* @parent: the parent of the new node
* @value: the value of the new node
*
* Return: the new node on success
* NULL if it fails
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		parent->left->parent = newNode;
		newNode->left = parent->left;
	}

	parent->left = newNode;

	return (newNode);
}
