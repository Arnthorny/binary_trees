#include "binary_trees.h"


/**
 * max_val - Return the max value of two given numbers
 *
 * @num_1: First number to be checked.
 * @num_2: Second number to be checked.
 * Return: Larger value.
 */

size_t max_val(size_t num_1, size_t num_2)
{
	return (num_1 > num_2 ? num_1 : num_2);
}

/**
 * binary_tree_height - Measure the height of a binary tree.
 *
 * @tree: Pointer to root node of tree to be measured.
 * Return: 0 if tree is NULL else height of tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t max_l = 0, max_r = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	max_l = binary_tree_height(tree->left);
	max_r = binary_tree_height(tree->right);
	return (max_val(max_l, max_r) + 1);
}
