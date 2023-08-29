#include "binary_trees.h"

/**
 * binary_tree_is_full_h - Helper to check if a binary tree is full.
 *
 * @tree: Pointer to root node of tree to check.
 * @s: Pointer to starting root node of tree.
 * Return: 0 if tree is NULL else 1 if tree is full otherwise 0..
 */

int binary_tree_is_full_h(const binary_tree_t *tree, const binary_tree_t *s)
{
	size_t check_l_nodes = 1, check_r_nodes = 1;

	if (!s)
		return (0);
	else if (!tree)
		return (1);

	check_l_nodes = binary_tree_is_full_h(tree->left, s);
	check_r_nodes = binary_tree_is_full_h(tree->right, s);

	if ((tree->right && tree->left) || (!tree->right && !tree->left))
		return (check_l_nodes & check_r_nodes & 1);
	else
		return (check_l_nodes & check_r_nodes & 0);
}

/**
 * binary_tree_is_full - Check if a binary tree is full.
 *
 * @tree: Pointer to root node of tree to check.
 * Return: 0 if tree is NULL else 1 if tree is full otherwise 0..
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	return (binary_tree_is_full_h(tree, tree));
}
