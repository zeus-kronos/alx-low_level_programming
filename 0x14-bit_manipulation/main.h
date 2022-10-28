#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#include <unistd.h>
#include <stdio.h>

int _putchar(char);
unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int get_endianness(void);

#endif /* #ifndef BIT_MANIPULATION_H_ */
