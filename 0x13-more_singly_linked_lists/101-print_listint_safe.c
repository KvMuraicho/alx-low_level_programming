#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: The list to be printed.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t node_count = 0;
    const listint_t *slow = head, *fast = head;

    while (head)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        node_count++;
        head = head->next;

        if (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        else
            break;

        if (slow == fast)
        {
            printf("-> [%p] %d\n", (void *)slow, slow->n);
            exit(98);
        }
    }

    return node_count;
}

