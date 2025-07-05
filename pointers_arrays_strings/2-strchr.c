#include "main.h"
#include <stddef.h>  /* For NULL */

/**
 * _strchr - locates a character in a string
 * @s: string to search in
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of c in s,
 *         or NULL if c is not found
 */
char	*_strchr(char *s, char c)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);

	return (NULL);
}
