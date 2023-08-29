#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: The size of a binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	size = tree ? 1 + binary_tree_size(tree->left) : 0;
	size += tree ? binary_tree_size(tree->right) : 0;
	return (size);
}
