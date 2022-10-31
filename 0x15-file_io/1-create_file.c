#include "main.h"

/**
  * _strlen - length of a string
  * @s: input char
  * Return: length of a string
**/

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
* create_file - check the code for Holberton School students.
* @filename: file to create.
* @text_content: info to write into the file.
* Return: 1 on success, -1 on failure
*/

int create_file(const char *filename, char *text_content)
{
	ssize_t nletters;
	int file;

	if (!filename)
		return (1);
	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		nletters = write(file, text_content, _strlen(text_content));
		if (nletters == -1)
		{
			close(file);
			return (-1);
		}
	}
	close(file);
	return (1);
}
