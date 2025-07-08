#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenates s1 and first n bytes of s2
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated concatenated string,
 *         or NULL if allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *result;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* If n >= len2, use entire s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory for concatenated string + null terminator */
	result = malloc(len1 + n + 1);
	if (result == NULL)
		return (NULL);

	/* Copy s1 */
	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	/* Copy first n bytes of s2 */
	for (j = 0; j < n; j++)
		result[i + j] = s2[j];

	/* Null terminate */
	result[i + j] = '\0';

	return (result);
}
