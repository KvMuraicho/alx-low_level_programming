#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the start of the list
 * @index: index of the node, starting from 0
 * 
 * Return: the nth node of a listint_t linked list or NULL if the node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
		{
			return (head);
		}
		i++;
		head = head->next;
	}

	return (NULL);
}
