#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int digit1, digit2;

	for (digit1 = 0; digit1 < 9; digit1++)
	{
		for (digit2 = digit1 + 1; digit2 <= 9; digit2++)
		{
			printf("%02d, %02d", digit1, digit2);
			putchar(',');
			putchar(',');
			if (!(digit1 != 8 || digit2 != 9))
			{
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
