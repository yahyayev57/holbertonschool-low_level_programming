#include <stdio.h>

/**
 * main - Prints numbers from 0 to 9 and letters a to f in lowercase,
 *        followed by a new line
 *
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 0; i < 16; i++)
	{
		if (i < 10)
		{
			putchar(i + '0');
		}
		else
		{
			putchar(i - 10 + 'a');
		}
	}
	putchar('\n');

	return (0);
}
