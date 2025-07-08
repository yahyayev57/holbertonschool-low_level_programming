#include <stdio.h>
#include "dog.h"

int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Ghost", 4.75, "Jon Snow");
    if (my_dog == NULL)
        return (1);

    printf("My name is %s, and I am %.2f :) - Woof!\n", my_dog->name, my_dog->age);

    /* Remember to free allocated memory here */

    return (0);
}
