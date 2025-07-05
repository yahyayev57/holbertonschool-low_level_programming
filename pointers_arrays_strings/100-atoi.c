#include "main.h"
#include <limits.h>  /* For INT_MAX, INT_MIN */

/**
 * _atoi - converts a string to an integer with overflow protection
 * @s: the string to convert
 *
 * Return: the integer representation of the string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	unsigned int result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			; /* do nothing */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;

			/* Check overflow before multiplying and adding */
			if (result > (unsigned int)(INT_MAX / 10) ||
			    (result == (unsigned int)(INT_MAX / 10) && (s[i] - '0') > INT_MAX % 10))
			{
				if (sign == 1)
					return (INT_MAX);
				else
					return (INT_MIN);
			}

			result = result * 10 + (s[i] - '0');
		}
		else if (started)
			break;

		i++;
	}

	if (sign == -1)
		return (-((int)result));
	return ((int)result);
}
