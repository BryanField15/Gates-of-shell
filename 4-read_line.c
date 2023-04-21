#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 *main - prints "$ ", waits for a users command, prints it on the next line
 *Return: 0 on success, -1 on failure
 */

int main (void)
{
	char *user_input;
	size_t len;
	ssize_t read; 

	user_input = NULL;
	len = 0;

	printf("$ ");
	read = getline(&user_input, &len, stdin);
	if (read == -1)
	{
		printf("%d\n", errno);
		free(user_input);
		return (-1);
	}
	printf("%s", user_input);
	free(user_input);
	return (0);
}
