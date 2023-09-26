#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 * @head: double pointer to the beginning of the listint_t list
 *
 * Return: data of the head node or 0 if list is empty
 */
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int n;

    if (head == NULL || *head == NULL)
    {
        return (0);
    }

    temp = *head;
    n = temp->n;
    *head = (*head)->next;
    free(temp);

    return (n);
}

