#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if a node is root node.
 *
 * @node: Pointer of node to be checked.
 * Return: 1 if node is root else 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && node->parent == NULL)
		return (1);
	return (0);
}
