#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_digit_str - checks if a string contains only digits
 * @s: input string
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit_str(char *s)
{
	int i = 0;

	if (s[0] == '\0') /* empty string */
		return (0);

	while (s[i])
	{
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - adds positive numbers passed as arguments
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_digit_str(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
