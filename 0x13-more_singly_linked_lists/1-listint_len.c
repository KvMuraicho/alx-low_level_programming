#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: pointer to the start of the list
 *
 * Return: number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
    size_t nodes = 0;  /* Counter for number of nodes */

    while (h != NULL)
    {
        nodes++;
        h = h->next;  /* Move to the next node */
    }

    return nodes;
}

