#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog.
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog struct or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    char *name_copy, *owner_copy;

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    name_copy = strdup(name);
    if (name_copy == NULL)
    {
        free(dog);
        return (NULL);
    }

    owner_copy = strdup(owner);
    if (owner_copy == NULL)
    {
        free(name_copy);
        free(dog);
        return (NULL);
    }

    dog->name = name_copy;
    dog->age = age;
    dog->owner = owner_copy;

    return (dog);
}
