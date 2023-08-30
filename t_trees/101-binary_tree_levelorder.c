#include "binary_trees.h"


/**
 * push_node - Function to push a node to the
 * queue used for the level-order traversal.
 * @queue: Pointer to pointer to queue.
 * @l: Pointer to left child node to be inserted.
 * @r: Pointer to right child node to be inserted.
 */

void push_node(bfs_queue_t **queue, binary_tree_t *l, binary_tree_t *r)
{
	bfs_queue_t *last = NULL, *tmp = NULL;
	binary_tree_t *arr_child[] = {l, r};
	int i = -1;

	if (!(*queue))
		return;

	while (++i < 2)
	{
		last = (*queue)->last;
		if (arr_child[i])
		{

			tmp = malloc(sizeof(*tmp));
			if (!tmp)
				return;

			tmp->node = arr_child[i];
			tmp->last = NULL;
			tmp->next = NULL;
			last->next = tmp;
			(*queue)->last = tmp;
		}
	}
}

/**
 * pop_node - Function to pop a node from queue
 * used in the level-order traversal.
 * @queue: Pointer to pointer to queue.
 */
void pop_node(bfs_queue_t **queue)
{
	bfs_queue_t *tmp = NULL;

	if (!(*queue))
		return;

	tmp = *queue;
	*queue = (*queue)->next;

	if (*queue)
		(*queue)->last = tmp->last;

	free(tmp);
}

/**
 * traverse_tree_bfs - Helper Function to traverse tree.
 * @queue: Pointer to pointer to queue.
 * @func: A function used to operate on each node of tree.
 */
void traverse_tree_bfs(bfs_queue_t **queue, void (*func)(int))
{
	binary_tree_t *curr_node = NULL;

	do {
		curr_node = (*queue)->node;
		func(curr_node->n);
		if (curr_node)
			push_node(queue, curr_node->left, curr_node->right);
		pop_node(queue);
	} while (*queue);
}

/**
 * binary_tree_levelorder - Function to traverse tree
 * using the level order method(BFS).
 * @tree: Tree to be traversed.
 * @func: A function used to operate on each node of tree.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	bfs_queue_t **queue = NULL, *head = NULL;

	if (!tree || !func)
		return;

	head = malloc(sizeof(*head));
	if (!head)
		return;

	head->node = (binary_tree_t *)tree;
	head->next = NULL;

	queue = &head;
	(*queue)->last = head;

	traverse_tree_bfs(queue, func);
}
