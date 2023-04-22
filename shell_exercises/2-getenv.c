#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 *_getenv - a function that gets an environment variable
 *@name: pointer to the name of the env variable to be fetched
 *Return: NULL if not found; pointer to the corresponding value string
 */

char *_getenv(const char *name)
{
	int i;
	char * value;
	char *env_name;

	i = 0;
	value = NULL;

	while (environ[i] != NULL)
	{
		env_name = strtok(strdup(environ[i]), "=");
		if (env_name != NULL && strcmp(env_name, name) == 0)
		{
			value = strtok(NULL, "=");
			if (value == NULL)
			{
				value = "";
			}
			break;
		}
		free(env_name);
		i = i + 1;
	}
	return (value);
}
