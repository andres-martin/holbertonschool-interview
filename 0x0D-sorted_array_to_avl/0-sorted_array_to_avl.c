#include "binary_trees.h"

/**
 * new_node - Creates a new node
 * @parent: new_node's parent
 * @data: new_node's data
 * Return: new node
 */

avl_t *new_node(avl_t *parent, int data)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);
	new_node->n = data;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * array_to_bts - builds a BTS from a sorted array
 * @array: source sorted array
 * @start: starting point
 * @end: end of the array
 * @parent_node: parent node
 * Return: avl_t root node
 */

avl_t *array_to_bts(int *array, int start, int end, avl_t *parent_node)
{
	avl_t *root;

	if (start > end)
		return (NULL);

	int middle = (start + end) / 2;

	root = new_node(parent_node, array[middle]);

	root->left = array_to_bts(array, start, middle - 1, root);
	root->right = array_to_bts(array, middle + 1, end, root);

	return (root);
}


/**
 * sorted_array_to_avl - builds a BTS from a sorted array
 * @array: source sorted array
 * @size: size of the source array
 * Return: avl_t root node
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (array_to_bts(array, 0, size - 1, NULL));
}
