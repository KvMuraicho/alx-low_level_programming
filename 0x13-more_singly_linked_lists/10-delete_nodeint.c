#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes a node at a given position.
 * @head: Double pointer to the start of the list.
 * @index: Index of the node that should be deleted, index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *next_node;
    unsigned int i;

    if (!head || !*head)
        return (-1);

    current = *head;
    if (index == 0)
    {
        *head = current->next;
        free(current);
        return (1);
    }

    for (i = 0; i < index - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (!current || !current->next)
        return (-1);

    next_node = current->next->next;
    free(current->next);
    current->next = next_node;

    return (1);
}

