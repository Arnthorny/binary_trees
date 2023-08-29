#include "binary_trees.h"


/**
 * binary_tree_leaves - Count the number of leaves in a binary tree.
 *
 * @tree: Pointer to root node of tree to count number of leaves.
 * Return: 0 if tree is NULL else number of leaves in tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_l_leaf = 0, count_r_leaf = 0;

	if (!tree)
		return (0);

	count_l_leaf = binary_tree_leaves(tree->left);
	count_r_leaf = binary_tree_leaves(tree->right);

	if (!tree->left && !tree->right)
		return (count_l_leaf + count_r_leaf + 1);
	else
		return (count_l_leaf + count_r_leaf);
}
