#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list.
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t nodes = 0;
    const listint_t *slow, *fast, *start = NULL, *current;

    if (!head)
        exit(98);

    slow = head;
    fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        nodes++;

        if (slow == fast)
        {
            start = slow;
            break;
        }
    }

    current = head;
    while (current && (!start || current != start->next))
    {
        printf("[%p] %d\n", (void *)current, current->n);
        current = current->next;
    }

    if (start)
        printf("-> [%p] %d\n", (void *)start, start->n);

    return nodes;
}
