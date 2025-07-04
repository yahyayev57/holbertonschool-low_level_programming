#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase except 'q' and 'e',
 *        followed by a new line
 *
 * Return: Always 0
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		if (ch != 'e' && ch != 'q')
		{
			putchar(ch);
		}
	}
	putchar('\n');

	return (0);
}
