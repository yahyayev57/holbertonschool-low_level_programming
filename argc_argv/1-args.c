#include <stdio.h>

/**
 * main - prints the number of arguments passed to the program
 * @argc: argument count
 * @argv: argument vector (unused)
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	(void)argv; /* unused parameter */
	printf("%d\n", argc - 1);
	return (0);
}
