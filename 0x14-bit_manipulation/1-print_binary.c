#include "main.h"

/**
 * print_binary - Prints a number as binary string
 * @n: The number to print in binary.
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int size = sizeof(unsigned long int) * 8;
	int i;
	int bit;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		bit = (n >> i) & mask;
		_putchar(bit + '0');
	}
}
