#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is a leaf node.
 *
 * @node: Pointer of node to be checked.
 * Return: 1 if node is a leaf else 0.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
