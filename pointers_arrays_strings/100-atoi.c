#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer representation of the string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		/* Handle signs before the number */
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			; /* do nothing */
		/* When digit found, start conversion */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = result * 10 + (s[i] - '0');
		}
		/* If conversion started and char is not digit, break */
		else if (started)
			break;

		i++;
	}

	return (sign * result);
}
