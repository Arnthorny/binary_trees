#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree using post-order traversal.
 *
 * @tree: Tree to be traversed.
 * @func: Pointer to function to be called on each node
 * Return: 1 if node is root else 0.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
