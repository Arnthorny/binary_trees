#include "binary_trees.h"

/**
 * binary_tree_sibling - Function to find the sibling of a node.
 *
 * @node: Pointer to node to check for sibling.
 *
 * Return: Pointer to sibling else NULL if parent is NULL
 * or if node is NULL or node has no sibling.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
