#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_loop_start - Finds the starting node of a loop.
 * @head: Pointer to the head of the list.
 * @meeting: Point where hare and tortoise pointers met.
 * Return: Pointer to the start of the loop, or NULL if no loop.
 */
const listint_t *find_loop_start(const listint_t *head, const listint_t *meeting)
{
	while (head != meeting)
	{
		head = head->next;
		meeting = meeting->next;
	}
	return (head);
}

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the start of the list.
 * Return: Number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;
	const listint_t *loop_start = NULL;
	size_t nodes = 0;

	if (!head)
		exit(98);

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			loop_start = find_loop_start(head, hare);
			break;
		}
	}

	tortoise = head;
	while (tortoise && tortoise != loop_start)
	{
		nodes++;
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
	}

	if (loop_start)
	{
		do
		{
			nodes++;
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			tortoise = tortoise->next;

			if (tortoise == loop_start)
			{
				printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
			}
		} while (tortoise != loop_start);
	}

	return (nodes);
}

