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
 * binary_tree_is_perfect_h - Helper to check if a binary tree is perfect.
 *
 * @tree: Pointer to root node of tree to check.
 * @s: Pointer to starting root node of tree.
 * Return: 0 if tree is NULL else 1 if tree is perfect otherwise 0.
 */

int binary_tree_is_perfect_h(const binary_tree_t *tree, const binary_tree_t *s)
{
	int max_l = 0, max_r = 0;
	const binary_tree_t *t = tree;

	if (!tree)
		return (0);

	max_l = binary_tree_is_perfect_h(tree->left, s);
	max_r = binary_tree_is_perfect_h(tree->right, s);

	if (t != s && !((t->right && t->left) || (!t->right && !t->left)))
		return (-1);
	else if (tree != s && (max_l == -1 || max_r == -1))
		return (-1);
	else if (t != s && ((t->right && t->left) || (!t->right && !t->left)))
		return (max_val(max_l, max_r) + 1);
	else if (tree == s && (max_l == -1 || max_r == -1))
		return (0);
	else
		return (max_l == max_r);
}

/**
 * binary_tree_is_perfect - Check if a binary tree is full.
 *
 * @tree: Pointer to root node of tree to check.
 * Return: 0 if tree is NULL else 1 if tree is perfect otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (binary_tree_is_perfect_h(tree, tree));
}
