#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a node of type listint_t into a singled linked list
 * @head: pointer to head of list
 * @number: number to be inserted in new node
 * Return: address of new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current_node;

	current_node = *head;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	if (!current_node || number < current_node->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}


	new_node->n = number;

	while (current_node->next && number > current_node->next->n)
		current_node = current_node->next;

	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
