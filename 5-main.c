#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *main - Entry point. Splits a string and prints each word on a new line.
 *@argc: The number of command-line arguments provided.
 *@argv: An array of pointers to the strings which are those arguments.
 *Return: Always 0 (success).
*/

int main(int argc, char *argv[])
{
	char **words;
	int i;

	if (argc != 2)
	{
		printf("Usage: %s \"<string to split>\"\n", argv[0]);
		return (1);
	}
	words = split_string(argv[1], " ");
	if (words == NULL)
	{
		printf("Failed to split string\n");
		return (1);
	}
	i = 0;
	while (words[i] != NULL)
	{
		printf("%s\n", words[i]);
		i = i + 1;
	}
	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i = i + 1;
	}
	free(words);
	return (0);
}
