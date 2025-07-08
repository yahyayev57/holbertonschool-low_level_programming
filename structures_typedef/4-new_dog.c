#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * _strlen - returns length of a string
 */
static int _strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

/**
 * _strcpy - copies string src to dest
 */
static char *_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    int len_name, len_owner;

    dog = malloc(sizeof(dog_t));
    if (!dog)
        return (NULL);

    len_name = _strlen(name);
    dog->name = malloc(len_name + 1);
    if (!dog->name)
    {
        free(dog);
        return (NULL);
    }
    _strcpy(dog->name, name);

    len_owner = _strlen(owner);
    dog->owner = malloc(len_owner + 1);
    if (!dog->owner)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }
    _strcpy(dog->owner, owner);

    dog->age = age;

    return (dog);
}
