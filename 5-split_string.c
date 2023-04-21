#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - splits a string and returns an array of words
 * @str: the string to split
 * @delim: the delimiter to use for splitting
 * Return: an array of words
 */

char **split_string(char *str, const char *delim)
{
	char *copy;
	char *token;
	int count;
	char **word_array;
	int i;

	copy = strdup(str);
	if (copy == NULL)
	{
		return (NULL);
	}

	token = strtok(copy, delim);
	count = 0;
	while (token != NULL)
	{
		count = count + 1;
		token  = strtok(NULL, delim);
	}
	word_array = malloc(sizeof(*word_array) * (count + 1));
	if (word_array == NULL)
	{
		free(copy);
		return (NULL);
	}
	i = 0;
	token = strtok(str, delim);
	while (i < count)
	{
		word_array[i] = strdup(token);
		if (word_array[i] == NULL)
		{
			free(copy);
			while (i > 0)
			{
				free(word_array[i - 1]);
				i = i - 1;
			}
			free(word_array);
			return (NULL);
		}
		i = i + 1;
		token = strtok(NULL, delim);
	}
	word_array[count] = NULL;
	free(copy);
	return (word_array);
}
