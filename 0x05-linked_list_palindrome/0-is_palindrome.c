#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: double pointer to head node
 *
 * Return: 0 if not palindrome 1 otherwhise
 */

int is_palindrome(listint_t **head)
{
	int array_values[BLOCK_SIZE];
	int length = 0, min, max;
	const listint_t *current_node;

	current_node = *head;

	while (current_node)
	{
		array_values[length] = current_node->n;
		current_node = current_node->next;
		length++;
	}

	for (min = 0, max = length - 1; min < (length  - 1) / 2; min++, max--)
	{
		if (array_values[min] != array_values[max])
			return (0);
	}

	return (1);
}

