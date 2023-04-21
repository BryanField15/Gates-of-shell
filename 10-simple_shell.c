#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * _exec - execve example
 *
 * Return: Always 0.
 */

int _exec(char *user_input)
{
    char *argv[] = {user_input, NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}


/**
 *main - prints "$ ", waits for a users command, prints it on the next line
 *Return: 0 on success, -1 on failure
 */

int main (void)
{
	char *user_input;
	size_t len;
	ssize_t read;
	pid_t child_pid;
	int status;

	while (1)
	{

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
		user_input = strtok(user_input, "\n");
		printf("%s", user_input);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (user_input == NULL)
			{
				return (-1);
			}
			_exec(user_input);
			printf("Error after execve\n");
			return (-1);
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}
		free(user_input);
	}
	return (0);
}
