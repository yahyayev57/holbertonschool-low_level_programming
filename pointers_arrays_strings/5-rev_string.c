#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int start = 0, end = 0;
	char temp;

	/* find length */
	while (s[end] != '\0')
		end++;

	/* move end to last character */
	end--;

	/* swap characters */
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
