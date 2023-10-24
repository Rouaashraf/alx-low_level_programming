#include <stdlib.h>
#include "lists.h"
/**
 * free_listint2 - frees a list of ints
 * @head: address of pointer to first node
 *
 * Return:void
 */

void free_listint2(listint_t **head)
{
	listint_t *current = *head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
