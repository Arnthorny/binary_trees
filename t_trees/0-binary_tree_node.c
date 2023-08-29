#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node.
 *
 * @parent: Pointer to parent node of node to be created
 * @value: Value to put in new node.
 *
 * Return: Pointer to new node or NULL if error.
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
