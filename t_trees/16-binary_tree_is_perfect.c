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

/**
 * max_val - Return the max value of two given numbers
 *
 * @num_1: First number to be checked.
 * @num_2: Second number to be checked.
 * Return: Larger value.
 */

int max_val(int num_1, int num_2)
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

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 *
 * @tree: Pointer to root node of tree to check.
 * Return: 0 if tree is NULL else 1 if tree is perfect otherwise 0.
 *
 * Description: The total number of nodes in a
 * perfect binary tree with height h is 2^(h+1) - 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int actual_nodes = 0, expected_nodes = 0, h = 0;

	if (!tree)
		return (0);

	h = binary_tree_height(tree);

	expected_nodes = (1 << (h + 1)) - 1;
	actual_nodes = binary_tree_size(tree);

	return (expected_nodes == actual_nodes);
}
