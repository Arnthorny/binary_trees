#include "binary_trees.h"


/**
 * is_descendant - Function to determine if node is descendant of ancestor.
 *
 * @ancestor: Pointer to ancestor node.
 * @node: Pointer to node to be checked.
 *
 * Return: 1 if node is a descendant else 0.
 */

int is_descendant(const binary_tree_t *ancestor, const binary_tree_t *node)
{
	int l_flag = 0, r_flag = 0;

	if (!ancestor)
		return (0);
	else if (node == ancestor)
		return (1);

	l_flag = is_descendant(ancestor->left, node);
	r_flag = is_descendant(ancestor->right, node);
	return (l_flag || r_flag);
}

/**
 * binary_trees_ancestor - Function to find the
 * lowest common ancestor of two nodes.
 *
 * @f: Pointer to first node.
 * @s: Pointer to second node.
 *
 * Return: Pointer to common ancestor else NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *f,
		const binary_tree_t *s)
{
	binary_tree_t *tmp_ancestor = NULL;
	const binary_tree_t *tmp_descendant = NULL;


	if (!f || !s)
		return (NULL);

	if (f)
	{
		tmp_ancestor = (binary_tree_t *)f;
		tmp_descendant = s;
	}
	else if (s)
	{
		tmp_ancestor = (binary_tree_t *)s;
		tmp_descendant = f;
	}

	while (tmp_ancestor && tmp_descendant)
	{
		if (is_descendant(tmp_ancestor, tmp_descendant))
			return (tmp_ancestor);
		tmp_ancestor = tmp_ancestor->parent;
	}

	return (tmp_ancestor);
}
