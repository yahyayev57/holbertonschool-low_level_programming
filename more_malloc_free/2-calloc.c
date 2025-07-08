#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array, initializes it to zero
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to allocated memory or NULL on failure
 *         or if nmemb or size is 0
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total_size;
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total_size; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}
