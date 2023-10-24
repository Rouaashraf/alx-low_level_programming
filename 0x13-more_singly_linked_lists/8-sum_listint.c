#include "lists.h"

/**
 * sum_listint - Computes the sum of all the data in a linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: The sum of all the data in the list.
 */

int sum_listint(const listint_t *head)
{
	const listint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
