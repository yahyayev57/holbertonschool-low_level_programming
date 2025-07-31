#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index `index` of
 *                            a doubly linked list.
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete (starts at 0)
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    temp = *head;

    /* If head needs to be removed */
    if (index == 0)
    {
        *head = temp->next;
        if (*head)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    /* Traverse to the node at index */
    for (i = 0; temp != NULL && i < index; i++)
        temp = temp->next;

    /* If index is out of bounds */
    if (temp == NULL)
        return (-1);

    /* Change links of previous and next nodes */
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
    return (1);
}
