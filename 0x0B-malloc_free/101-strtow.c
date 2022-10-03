#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
* count_words - function that count words in a string
* separated by a blank space
* Return: number of words in the string
* @str: pointer to the string
*/

int count_words(char *str)
{
	int words = 0;
	int flagbs = 0;
	int i = 0;

	while (*(str + i))
	{
		if ((*(str + i) == ' ' || *(str + i + 1) == 0) && flagbs)
		{
			flagbs = 0;
			words++;
		}
		if (*(str + i) != ' ')
			flagbs = 1;
		i++;
	}
	if (*(str + i - 1) != ' ' && *(str + i - 2) == ' ')
		words++;
	if (i == 1 && *str != ' ')
		words++;
	return (words);
}

/**
* look_pos - function that stores the begining and the end position of a word
* in a string
* @str: pointer to the string
* @pos: pointer ti the array used to store the positions
*/

void look_pos(char *str, int *pos)
{
	int flagw = 1;
	int k = 0;
	int i = 0;

	while (*(str + i))
	{
		if (*(str + i) != ' '  && *(str + i + 1) == 0 && flagw)
		{
			*(pos + k) = i;
			*(pos + k + 1) = i;
		}
		if (*(str + i) != ' ' && *(str + i) != 0 && flagw)
		{
			flagw = 0;
			*(pos + k) = i;
			k++;
		}
		if (*(str + i + 1) == 0 && (flagw == 0))
			*(pos + k) = i;
		if (*(str + i + 1) == ' ' && *(str + i) != ' ')
		{
			*(pos + k) = i;
			k++;
		}
		if (*(str + i) == ' ')
			flagw = 1;
		i++;
	}
}
/**
* print_words - function that stores in m the words found in str
* Return: 1 if fail.
* @m: pointer to the matrix
* @pos: pointer to the array with positions
* @words: number of words
* @str: pointer to the string
*/

int print_words(int *pos, char **m, char *str, int words)
{
	int b = 0;
	int b1 = 0;
	int l = 0;

	for (b = 0; b < words; b++)
	{
		int p1 = *(pos + b1);
		int p2 = *(pos + b1 + 1);
		int sz = p2 - p1 + 2;
		*(m + b) = (char *)malloc(sizeof(char) * (sz));
		if (*(m + b) == NULL)
		{
			for (b = b - 1; b >= 0; b--)
				free(*(m + b));
			free(m);
			free(pos);
			return (1);
		}
		for (l = 0; l < sz - 1; l++, p1++)
			*(*(m + b) + l) = *(str + p1);
		*(*(m + b) + l) = '\0';
				b1 = b1 + 2;
	}
	*(m + b) = NULL;
	return (0);
}

/**
* strtow - function that returns a pointer to an array of strings (words)
* Return: pointer to the array
* @str: pointer to the array
*/

char **strtow(char *str)
{
	int words;
	char **m = NULL;
	int *pos = NULL;

	if (str == NULL || *str == 0)
		return (NULL);
	words = count_words(str);
	if (words == 0)
	{
		return (NULL);
	}
	m = (char **) malloc((sizeof(char *) * (words + 1)));
	if (m == NULL)
	{
		for (words = words - 1; words >= 0; words--)
			free(*(m + words));
		free(m);
		return (NULL);
	}
	pos = (int *)malloc(sizeof(int) * words * 2);
	if (pos == NULL)
	{
		free(m);
		free(pos);
		return (NULL);
	}
	look_pos(str, pos);
	if (print_words(pos, m, str, words))
	{
		return (NULL);
	}
	return (m);
}
