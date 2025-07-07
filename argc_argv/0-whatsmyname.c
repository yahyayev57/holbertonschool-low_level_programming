#include <stdio.h>

/**
 * main - prints the program's name
 * @argc: number of command line arguments (unused)
 * @argv: array of command line arguments
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	(void)argc; /* unused parameter */
	printf("%s\n", argv[0]);
	return (0);
}
