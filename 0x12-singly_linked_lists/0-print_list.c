#include "lists.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;

	return (i);
}

/**
 i* print_list - prints a linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */

size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)

	{
		printf("[%d] %s\n", _strlen(h->str), h->str ? h->str : "(nil)");
		h = h->next;
		i++;
	}

	return (i);
}
