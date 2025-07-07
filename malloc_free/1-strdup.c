#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space
 *           containing a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string,
 *         or NULL if str is NULL or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *dup;
	int i, length;

	if (str == NULL)
		return (NULL);

	/* Calculate length of the string */
	length = 0;
	while (str[length] != '\0')
		length++;

	/* Allocate memory for the duplicate string + null terminator */
	dup = malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);

	/* Copy string */
	for (i = 0; i < length; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}
