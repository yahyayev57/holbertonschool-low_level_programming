#include <stdio.h>
#include "dog.h"

int main(void)
{
	dog_t *my_dog;

	my_dog = new_dog("Ghost", 4.75, "Jon Snow");
	printf("My name is %s, I am %.2f, and my owner is %s\n",
	       my_dog->name, my_dog->age, my_dog->owner);
	free_dog(my_dog);

	return (0);
}
