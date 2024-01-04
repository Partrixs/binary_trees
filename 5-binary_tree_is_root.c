#include "binary_trees.h"

/**
 * binary_tree_is_root -  if a node is a root of a binary tree,
 * @node: Pointer to node to check.
 *
 * Return: If node is a root - 1.
 *         else - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}

