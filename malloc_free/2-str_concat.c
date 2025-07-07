#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated space in memory
 * @s1: first string (can be NULL, treated as empty string)
 * @s2: second string (can be NULL, treated as empty string)
 *
 * Return: pointer to the concatenated string,
 *         or NULL if malloc fails
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, len1, len2;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of s1 and s2 */
	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	/* Allocate memory for concatenated string + null terminator */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
		return (NULL);

	/* Copy s1 to concat */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Append s2 to concat */
	for (j = 0; j < len2; j++)
		concat[i + j] = s2[j];

	concat[i + j] = '\0';

	return (concat);
}
