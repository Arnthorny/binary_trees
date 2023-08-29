#include "binary_trees.h"


/**
 * binary_tree_nodes - Count the number of nodes
 * in a binary tree with at least 1 child.
 *
 * @tree: Pointer to root node of tree to count number of nodes.
 * Return: 0 if tree is NULL else number of nodes in tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_l_nodes = 0, count_r_nodes = 0;

	if (!tree)
		return (0);

	count_l_nodes = binary_tree_nodes(tree->left);
	count_r_nodes = binary_tree_nodes(tree->right);

	if (tree->right || tree->left)
		return (count_l_nodes + count_r_nodes + 1);
	else
		return (count_l_nodes + count_r_nodes);
}
