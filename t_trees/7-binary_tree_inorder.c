#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree using in-order traversal.
 *
 * @tree: Tree to be traversed.
 * @func: Pointer to function to be called on each node
 * Return: 1 if node is root else 0.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
