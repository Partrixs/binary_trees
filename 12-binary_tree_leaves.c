#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts leaves found in tree,
 * @tree: pointer to root node of tree that count leaves of,
 *
 * Return: no. of leaves in our given tree,
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}

