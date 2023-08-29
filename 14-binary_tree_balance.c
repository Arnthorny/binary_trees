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
		return (0);
	left = tree->left ? 1 + height(tree->left) : 0;
	right = tree->right ? 1 + height(tree->left) : 0;

	return (left > right ? left : right);
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
	if (height(tree) == 1)
	{
		if (tree->left)
			return (1);
		return (-1);
	}
	return (height(tree->left) - height(tree->right));
}
