#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to the start of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *next_node = NULL;

    while (*head)
    {
        next_node = (*head)->next;  
        (*head)->next = prev;      
        prev = *head;               
        *head = next_node;          
    }
    
    *head = prev;                   
    
    return (*head);
}

