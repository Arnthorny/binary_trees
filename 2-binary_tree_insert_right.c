#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the
 * right-child of another node.
 *
 * @parent: Pointer to the parent node to insert the right-child in.
 * @value: Value to be stored in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);
	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);
	if (parent->right)
	{
		parent->right->parent = node;
		node->right = parent->right;
	}
	parent->right = node;
	return (node);
}
