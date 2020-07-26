#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current_node;

	current_node = *head;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	if(!current_node || number < current_node->n)
	{
		new_node->next = current_node;
		*head = new_node;
		return (new_node);
	}


	new_node->n = number;

	while (current_node->next && number > current_node->next->n)
	{
		printf("Moviendo el puntero %i\n", current_node->n);
		current_node = current_node->next;
	}

	printf("Aqui quedo el puntero %i\n", current_node->n);
	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
