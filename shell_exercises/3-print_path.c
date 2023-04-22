#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_path - prints each directory contained PATH on a newline
 */

void print_path()
{
	char *path;;
	char *dir;

	path = getenv("PATH");

	if (path != NULL)
	{
		dir = strtok(path, ":");
		while (dir != NULL)
		{
			printf("%s\n", dir);
			dir = strtok(NULL, ":");
		}
	}
}
