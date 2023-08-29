#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary tree using pre-order traversal.
 *
 * @tree: Tree to be traversed.
 * @func: Pointer to function to be called on each node
 * Return: 1 if node is root else 0.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
