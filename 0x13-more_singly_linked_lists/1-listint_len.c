#include <stdlib.h>
#include "lists.h"

/**
 * listint_len  - prints a linked lists
 * @h: pointer to first node
 *
 * Return:size of list
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
