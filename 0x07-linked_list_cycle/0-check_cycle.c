#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to a pointer of the start of the list
 * @n: integer to be included in node
 * Return: address of the new element or NULL if it fails
 */

int check_cycle(listint_t *list)
{
        listint_t *slow_node;
        listint_t *fast_node;

        if (!list)
                return (0);

        fast_node = list->next;
        slow_node = list;

        while(slow_node->next && fast_node->next)
        {
                slow_node = slow_node->next;
                fast_node = fast_node->next->next;

                if (fast_node->n == slow_node->n)
                        return (1);
        }

        return (0);
}
