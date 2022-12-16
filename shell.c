#include "main.h"

/**
 * get_command - gets the name of the file to be executed by execve
 *
 * @str: full pathname of the file
 * @delim: delimiter, usually the '/' on Linux
 *
 * Return: name of the executable
*/
char *get_command(char *str, char *delim)
{
	char *prev, *cur;

	cur = _strtok(str, delim);
	while (cur != NULL)
		prev = cur, cur = strtok(NULL, delim);

	free(cur);
	return (prev);
}

/**
 * main - Entry point
 *
 * @ac: number of command line arguments passed into main
 * @av: array of command line arguments passed into main
 * @envp: array of environment variables
 *
 * Return: Always 0
*/
int main(
	int ac __attribute__((unused)),
	char *av[] __attribute__((unused)),
	char *envp[])
{
	char *path = NULL, *copy, delim = '/', *args[2];
	pid_t child;
	size_t len, n_char;
	int exec_status;

	while (true)
	{
		printf("#cisfun$ ");
		/* Get the path to the commannd to be executed from stdin */
		n_char = _getline(&path, &len, stdin);
		if (n_char == (size_t)-1)
			perror(av[0]), exit(EXIT_FAILURE);
		copy = strndup(path, strlen(path) - 1);
		/* args[0]: command in path to be run */
		args[0] = get_command(path, &delim), args[1] = '\0';
		if (*path == '\0' || *path == '\n')
			continue;
		else if (strcmp(path, "exit\n") != 0)
		{
			child = fork();
			if (child == -1)
				perror(av[0]), exit(EXIT_FAILURE);
			else if (child == 0)
			{
				exec_status = execve(copy, args, envp);
				if (exec_status == -1)
					perror(av[0]), exit(EXIT_FAILURE);
			} else if (child > 0)
				wait(NULL);
		} else if (strcmp(path, "exit\n") == 0)
			break;
	}
	free(path), free(copy);
	return (0);
}
