#include <stdio.h>
#include "dog.h"

/**
* init_dog - Initializes the dog struct variables
*
* @name: String literal
*
* @d: Pointer to struct dog
*
* @age: Age of the dog
*
* @owner: Owner of the dog
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		(*d).age = age;
		d->owner = owner;
	}
}
