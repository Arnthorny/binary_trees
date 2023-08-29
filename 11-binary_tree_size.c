#include "binary_trees.h"


/**
 * binary_tree_size - Measure the height of a binary tree.
 *
 * @tree: Pointer to root node of tree to be measured.
 * Return: 0 if tree is NULL else height of tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count_l = 0, count_r = 0;

	if (!tree)
		return (0);

	count_l = binary_tree_size(tree->left);
	count_r = binary_tree_size(tree->right);
	return (count_l + count_r + 1);
}
