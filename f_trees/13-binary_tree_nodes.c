#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at
 * least 1 child in a binary tree.
 *
 * @tree: Pointer to the root node of the tree
 * to count the number of nodes.
 *
 * Return: The number of nodes with at least 1-child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes;

	if (!tree)
		return (0);

	nodes = tree->left || tree->right ? 1 + binary_tree_nodes(tree->left) : 0;
	nodes += tree->left || tree->right ? binary_tree_nodes(tree->right) : 0;
	return (nodes);
}
