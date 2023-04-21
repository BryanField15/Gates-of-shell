#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *main - creates 5 child processes
 *
 *
 *Return: 0
 */

int main()
{
	pid_t child_pid;
	int i;
	char *cmd[] = {"ls", "-l", "/tmp", NULL};
	char *envp[] = {NULL};

	i = 1;

	while (i < 6)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: fork failed");
			exit(1);
		}
		else if (child_pid == 0)
		{
			printf("Child %d is executing\n", i);
			execve("/bin/ls", cmd, envp);
			exit(0);
		}
		else
		{
			wait(NULL);
			printf("Child %d exited\n\n", i);
		}
		i = i + 1;
	}
	return (0);
}
