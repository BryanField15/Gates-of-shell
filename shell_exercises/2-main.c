#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name);

/**
 *
 *
 *
 */

int main(void)
{
	char *home = _getenv("HOME");
	if (home != NULL)
	{
		printf("The HOME environment variable is set to: %s\n", home);
	}
	else
	{
		printf("The HOME environment variable is not set.\n");
	}

	return (0);
}
