#include "binary_trees.h"

/**
 * binary_tree_delete - removes a binary tree,
 * @tree: pointer to root node of tree to remove,
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}

