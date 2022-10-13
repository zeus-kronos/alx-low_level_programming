#ifndef FUNCTION_POINTERS_
#define FUNCTION_POINTERS_

#include <stddef.h>

int _putchar(char);
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif /* #ifndef FUNCTION_POINTERS_ */
