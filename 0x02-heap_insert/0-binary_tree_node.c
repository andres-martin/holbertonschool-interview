#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: Pointer to parent node
 * @value: value stored in node
 *
 * Return: pointer to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary_tree_node;

	new_binary_tree_node = malloc(sizeof(binary_tree_t));

	if (!new_binary_tree_node)
		return (NULL);

	new_binary_tree_node->parent = parent;
	new_binary_tree_node->n = value;
	new_binary_tree_node->left = NULL;
	new_binary_tree_node->right = NULL;

	return (new_binary_tree_node);
}
