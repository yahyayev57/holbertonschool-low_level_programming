#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line
 * @str: pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int length = 0, start, i;

	while (str[length] != '\0')
		length++;

	start = (length + 1) / 2;

	for (i = start; i < length; i++)
		_putchar(str[i]);

	_putchar('\n');
}
