#include "binary_trees.h"

/**
 * height - Measure the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of a binary tree.
 */
size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (-1);
	left = height(tree->left);
	right = height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree
 * to measure the balance factor.
 *
 * Return: 1 if balanced and 0 else.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (height(tree->left) - height(tree->right));
}
