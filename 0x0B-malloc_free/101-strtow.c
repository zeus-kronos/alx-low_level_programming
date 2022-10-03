#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
* strtow - splits a string to words
* @str: string to split
* Return: a point to an array of strings or NULL
*/

char **strtow(char *str)
{
	char **arr_words = NULL;
	int i, j = 0, wlen, slen, words = 0, sig = 0, pre_sig = 0;

	if (str == NULL)
		return (NULL);
	slen = strlen(str);
	for (i = 0; i < slen; i++)
	{
		sig = (str[i] == 32 || str[i] == '\t') ? 0 : 1;
		words = (pre_sig == 0 && sig == 1) ? words + 1 : words;
		pre_sig = sig;
	}
	if (words == 0)
		return (NULL);
	arr_words = malloc(words * sizeof(char *));
	if (arr_words == NULL)
	{
		free(arr_words);
		return (NULL);
	}
	words = 0;
	for (i = 0; i < slen; i++)
	{
		sig = (str[i] == 32 || str[i] == 9) ? 0 : 1;
		if (sig)
		{
			for (j = 0; str[i + j] != 32 && str[i + j] != 9; j++)
				;
			wlen = j;
			arr_words[words] = malloc(wlen * sizeof(char));
			if (arr_words[words] == NULL)
			{
				for (; words >= 0; words--)
					free(arr_words[words]);
				free(arr_words);
				return (NULL);
			}
			for (j = 0; j < wlen; j++)
			{
				arr_words[words][j] = str[i + j];
			}
			words++;
			i += wlen - 1;
		}
	}
	return (arr_words);
}
