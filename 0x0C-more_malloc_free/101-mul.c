#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void populateResult(char *dest, char *n1, int n1_len, char *n2, int n2_len);
int getLengthOfNum(char *str);
void print_result(char *src, int length);

/**
* main - entry point, multiplies two numbers
*
* @argc: integer, length of @argv
*
* @argv: one-dimensional array of strings, arguments of this program
*
* Return: 0, success
*/

int main(int argc, char *argv[])
{
	int num1_length, num2_length;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	num1_length = getLengthOfNum(argv[1]);

	if (!num1_length)
	{
		printf("Error\n");
		exit(98);
	}

	num2_length = getLengthOfNum(argv[2]);

	if (!num2_length)
	{
		printf("Error\n");
		exit(98);
	}

	result = malloc(num1_length + num2_length);

	if (!result)
		return (1);

	populateResult(result, argv[1], num1_length, argv[2], num2_length);

	print_result(result, num1_length + num2_length);
	printf("\n");
	free(result);

	return (0);
}

/**
* getLengthOfNum - length of numbers in a string
*
* @str: pointer to string of numbers
*
* Return: integer (SUCCESS) or
* NULL, if string includes char
*/

int getLengthOfNum(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return ('\0');

	}

	return (i);
}

/**
* populateResult - multiplies two numbers stored as string
* and stores result in @dest
*
* @dest: pointer to where @num1 * @num2 should be stored
*
* @n1: positive number stored as string in an array
*
* @n2: positive number stored as string in an array
*
* @n1_len: length of @n1
*
* @n2_len: length of @n2
*/

void populateResult(char *dest, char *n1, int n1_len, char *n2, int n2_len)
{
	int i, j, k, temp_value, non_carry_value;
	int carry_value = 0;
	char *multiplicand, *multiplier;

	if (n1_len > n2_len)
	{
		i = n1_len - 1;
		j = n2_len - 1;
		multiplicand = n1;
		multiplier = n2;
	}
	else
	{
		i = n2_len - 1;
		j = n1_len - 1;
		multiplicand = n2;
		multiplier = n1;
	}

	while (i >= 0)
	{
		k = i;

		while (k >= 0)
		{
			temp_value = ((multiplicand[k] - '0') * (multiplier[j] - '0'));
			temp_value += carry_value;

			if (j + 1 <= n2_len - 1 && dest[k + j + 1] >= '0' && dest[k + j + 1] <= '9')
				temp_value += dest[k + j + 1] - '0';

			if (temp_value < 10)
			{
				non_carry_value = temp_value;
				carry_value = 0;
			}
			else
			{
				non_carry_value = temp_value % 10;
				carry_value = temp_value / 10;
			}

			dest[k + j + 1] = non_carry_value + '0';
			k--;
		}

		if (carry_value)
			dest[k + j + 1] = carry_value + '0';

		carry_value = 0;

		if (j > 0)
			j--;
		else
			i = -1;
	}

	free(dest);
	free(multiplicand);
	free(multiplier);
}

/**
* print_result - prints numbers stored as string in a memory location
*
* @src: pointer to memory that stores numbers as strings
*
* @length: length of @src
*/

void print_result(char *src, int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		if (src[i] >= '0' && src[i] <= '9')
		printf("%c", src[i]);
	}
}
