#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if node is leaf of a binary tree,
 * @node: pointer to node to check,
 *
 * Return: If node is a leaf node - 1.
 *         Else - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}

