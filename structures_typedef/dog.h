#ifndef DOG_H
#define DOG_H

#include <stddef.h>

typedef struct dog
{
    char *name;
    float age;
    char *owner;
} dog_t;

void init_dog(dog_t *d, char *name, float age, char *owner);
void print_dog(dog_t *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif /* DOG_H */
