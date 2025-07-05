#include "main.h"

/**
 * print_triangle - prints a triangle of size 'size' using '#'
 * @size: the size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int row, space, hash;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		/* print leading spaces */
		for (space = size - row; space > 0; space--)
			_putchar(' ');

		/* print hashes */
		for (hash = 0; hash < row; hash++)
			_putchar('#');

		_putchar('\n');
	}
}
