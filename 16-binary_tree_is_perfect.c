#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);

/**
 * depth - for returning the depth of given node in a tree,
 *
 * @tree: pointer to node to measure depth of,
 *
 * Return: depth of node,
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * is_leaf - for checking if node is the leaf of a tree.
 * @node: pointer to node to check,
 *
 * Return: If node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
        return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}


/**
 * get_leaf - Returns the leaf of a tree,
 * @tree: pointer to the root node of tree to find leaf in,
 *
 * Return: pointer to first encountered leaf,
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - for checking if a tree is perfect with recursive action,
 * @tree: pointer to root node of tree to check,
 * @leaf_depth: depth of one leaf in the binary tree,
 * @level: the given Level of current node,
 *
 * Return: If our tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect,
 * @tree: pointer to root node of the tree to check,
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

