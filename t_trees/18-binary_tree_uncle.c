#include "binary_trees.h"

/**
 * binary_tree_uncle - Function to find the uncle of a node.
 *
 * @node: Pointer to node to check for uncle.
 *
 * Return: Pointer to uncle else NULL if node is NULL
 * or node has no uncle.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_p = NULL;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	grand_p = node->parent->parent;

	if (grand_p->left == node->parent)
		return (grand_p->right);
	else
		return (grand_p->left);
}
