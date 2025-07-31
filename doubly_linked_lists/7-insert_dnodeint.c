#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index in a dlistint_t list
 * @h: Double pointer to the head of the list
 * @idx: Index where the new node should be added (starts at 0)
 * @n: Value to store in the new node
 *
 * Return: Address of the new node, or NULL if it failed or idx is invalid
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;
	for (i = 0; temp != NULL && i < idx - 1; i++)
		temp = temp->next;

	if (temp == NULL)
		return (NULL);

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
