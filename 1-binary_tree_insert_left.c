#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert a node as the left child of another node.
 *
 * @parent: Pointer to node to insert left child in.
 * @value: Value to put in new node.
 *
 * Return: Pointer to new node else NULL if error or parent is NULL.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *tmp;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;

	if (!parent->left)
	{
		parent->left = node;
		node->left = NULL;
	}
	else
	{
		tmp = parent->left;
		node->left = tmp;
		tmp->parent = node;
		parent->left = node;
	}
	node->right = NULL;

	return (node);
}
