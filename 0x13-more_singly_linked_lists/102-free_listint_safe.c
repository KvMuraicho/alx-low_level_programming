#include "lists.h"
#include <stdlib.h>


/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *temp;
	listint_t *marker = (listint_t *)&marker;

	if (!h || !*h)
		return (0);

	while (*h && (*h != marker))
	{
		temp = *h;
		*h = (*h)->next;
		temp->next = marker;
		free(temp);
		count++;
	}

	*h = NULL;

	return (count);
}
