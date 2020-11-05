#include "binary_trees.h"

/**
 * newNode - Creates new node
 *
 * @parent: The node´s father
 * @n: the data of the node
 * Return: New Node
 */

avl_t *newNode(avl_t *parent, int n)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * arrayToTree - Add the array elemento to tree
 *
 * @array: array of numbers
 * @start: start the range
 * @end: end the range
 * @parent: parent's node
 * Return: root Node
 */

avl_t *arrayToTree(int array[], int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = newNode(parent, array[mid]);

	if (!root)
		return (NULL);

	root->left = arrayToTree(array, start, mid - 1, root);

	root->right = arrayToTree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: array of numbers
 * @size: size of the array
 * Return: root Node
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (arrayToTree(array, 0, size - 1, NULL));
}
