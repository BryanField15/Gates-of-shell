#include <stdio.h>
#include <stddef.h>

/**
 *main - prints all the arguments, without using ac
 *@ac: number of items in av
 *@av: NULL termimate string of arrays
 *Return: number of arguments ac
 */

int main(int ac, char **av)
{
	int i = 0;

	if (av == NULL)
	{
		printf("Error! av is NULL\n");
		return (-1);
	}

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i = i + 1;

		if (i != ac)
		{
			printf("Error! av[%d] is NULL and ac is %d\n", i, ac);
			return (-1);
		}
	}
	return (ac);
}
