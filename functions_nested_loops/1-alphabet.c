#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times in lowercase,
 *                     followed by a new line each time.
 */
void print_alphabet_x10(void)
{
	int i, j;
	char ch;

	for (i = 0; i < 10; i++)
	{
		ch = 'a';
		for (j = 0; j < 26; j++)
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
	}
}
