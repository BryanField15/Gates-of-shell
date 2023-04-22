#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[], char *env[])
{
	printf("The adddress of the env is %p\n", env);
	printf("The address of the environ is %p\n", environ);

	return (0);
}
