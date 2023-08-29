#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right child of another node.
 *
 * @parent: Pointer to node to insert right child in.
 * @value: Value to put in new node.
 *
 * Return: Pointer to new node else NULL if error or parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *tmp;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;

	if (!parent->right)
	{
		parent->right = node;
		node->right = NULL;
	}
	else
	{
		tmp = parent->right;
		node->right = tmp;
		tmp->parent = node;
		parent->right = node;
	}
	node->left = NULL;

	return (node);
}
