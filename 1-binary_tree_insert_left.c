#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts node as a left-child of
 *                           of next in binary tree,,
 * @parent: pointer to node which inserts left-child in,
 * @value: value to store in new node,
 *
 * Return: If parent is NULL or error happens - NULL,
 *         else - pointer to new node,
 *
 * Description: If parent already has left-child, new node
 *              changes its place and old left-child is set as
 *              left-child of new node,
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}

