#include "binary_trees.h"


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
 * binary_tree_bal_helper - Helper to measure
 * the balance factor for a binary tree.
 *
 * @tree: Pointer to current node of tree to be measured.
 * @s: Root Node.
 * Return: 0 if tree is NULL else balance factor of tree.
 */

int binary_tree_bal_helper(const binary_tree_t *tree, const binary_tree_t *s)
{
	int max_l = 0, max_r = 0;

	if (!tree)
		return (0);

	max_l = binary_tree_bal_helper(tree->left, s);
	max_r = binary_tree_bal_helper(tree->right, s);

	if (tree != s)
		return (max_val(max_l, max_r) + 1);
	else
		return (max_l - max_r);
}

/**
 * binary_tree_balance - Measure the balance factorfor a binary tree.
 *
 * @tree: Pointer to root node of tree to be measured.
 * Return: 0 if tree is NULL else balance factor of tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	return (binary_tree_bal_helper(tree, tree));
}
