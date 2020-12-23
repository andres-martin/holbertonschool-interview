#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * _preorder - traverse a binary tree using pre-order traversal
 *
 * @head: pointer to root
 * @node: pointer to node in the tree
 * @h: height of heap
 * @l: layer on the heap
 **/
void _preorder(heap_t *head, heap_t **node, size_t h, size_t l)
{
	if (!head)
		return;
	if (h == l)
		*node = head;
	l++;
	if (head->left)
		_preorder(head->left, node, h, l);
	if (head->right)
		_preorder(head->right, node, h, l);
}

/**
 * _heapify - binary tree Heapsort
 * @temp: pointer to the root
 * Return: pointer to the last node
 **/

heap_t *_heapify(heap_t *temp)
{
	int current_value;

	while (temp->left || temp->right)
	{
		if (!temp->right || temp->left->n > temp->right->n)
		{
			current_value = temp->n;
			temp->n = temp->left->n;
			temp->left->n = current_value;
			temp = temp->left;
		}
		else if (!temp->left || temp->left->n < temp->right->n)
		{
			current_value = temp->n;
			temp->n = temp->right->n;
			temp->right->n = current_value;
			temp = temp->right;
		}

	}
	return (temp);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/

int heap_extract(heap_t **root)
{
	int value;
	heap_t *temp, *node;

	if (!root || !*root)
		return (0);
	temp = *root;
	value = temp->n;
	if (!temp->left && !temp->right)
	{
		*root = NULL;
		free(temp);
		return (value);
	}
	_preorder(temp, &node, _height(temp), 0);
	temp = _heapify(temp);
	temp->n = node->n;
	(node->parent->right) ?
		(node->parent->right = NULL) : (node->parent->left = NULL);
	free(node);
	return (value);
}
