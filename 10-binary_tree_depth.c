#include "binary_trees.h"

/**
 * binary_tree_depth - Measure the depth of a binary tree's node.
 *
 * @tree: Pointer of node to be measured.
 * Return: 0 if tree is NULL else depth of node.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}
