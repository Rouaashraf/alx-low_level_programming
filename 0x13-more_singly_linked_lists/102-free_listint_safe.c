#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: This function frees a linked list of type listint_t.
 *              It safely handles lists with a possible loop by
 *              breaking the loop and freeing each node.
 *              The function takes a double pointer to the head of the list
 *              to be able to update the head correctly.
 */

size_t free_listint_safe(listint_t **head)
{
	size_t count = 0;
	listint_t *current;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	current = *head;
	while (current != NULL)
	{
		count++;
		if (current->next >= current)
		{
			*head = NULL;
			free(current);
			break;
		}
		temp = current;
		current = current->next;
		temp->next = NULL;
		free(temp);
	}
	*head = NULL;

	return (count);
}
