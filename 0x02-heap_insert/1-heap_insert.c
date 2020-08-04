#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to heap's root node
 * @value: value to be inserted in the new node
 * Return: pointer to the inserted node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	new_node = *root;

	if (!new_node)
	{
		*root = binary_tree_node(new_node, value);
		return (*root);
	}
}
