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
	right = tree->right ? 1 + height(tree->right) : 0;

	return (left > right ? left : right);
}

/**
 * print_current_level - Prints all nodes of a binary tree at a
 * particular height.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: Current level.
 */
void print_current_level(const binary_tree_t *tree, void (*func)(int),
		size_t level)
{
	if (!tree)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		print_current_level(tree->left, func, level - 1);
		print_current_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *		The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, h;

	if (!tree || !func)
		return;

	h = height(tree);
	for (i = 0; i <= h; i++)
		print_current_level(tree, func, i);
}
