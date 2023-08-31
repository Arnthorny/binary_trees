#include "binary_trees.h"



/**
 * binary_tree_rotate_left - Function to perform left-rotate on a tree
 * @tree: Tree to be rotated.
 * @func: A function used to operate on each node of tree.
 * Return: Pointer to new root node of rotated tree.
 * Description: When a tree(node) is left-rotated, it becomes the
 * left child of its right child and then bears the left
 * child of that right child as its right child.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;
	
	if (tree == NULL || !(tmp = tree->right))
		return (tree);
	
	tree->right = tmp->left;
	if (tmp->left)
		tmp->left->parent = tree;
	
	tmp->left = tree;
	
	tmp->parent = tree->parent;
	tree->parent = tmp;
	return (tmp);
}
