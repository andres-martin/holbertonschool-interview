#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to the start of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *slow_node;
	listint_t *fast_node;

	if (!list)
		return (0);

	fast_node = list->next;
	slow_node = list;

	while (slow_node->next && fast_node->next)
	{
		slow_node = slow_node->next;
		fast_node = fast_node->next->next;

		if (fast_node->n == slow_node->n)
			return (1);
	}

	return (0);
}
