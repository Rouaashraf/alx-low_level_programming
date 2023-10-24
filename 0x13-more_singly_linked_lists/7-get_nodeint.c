#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a linked list.
 * @head: Pointer to the head node of the list.
 * @index: Index of the node to retrieve.
 *
 * Return: Pointer to the nth node of the list, or NULL if it doesn't exist.
 */

listint_t *get_nodeint_at_index(const listint_t *head, unsigned int index)
{
	const listint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (listint_t *)current;
		count++;
		current = current->next;
	}

	return (NULL);
}
