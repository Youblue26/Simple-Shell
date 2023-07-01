#include "shell.h"

/**
 * bling - displays the prompt
 * @av: args variable
 * @env: environ variable
 * Return: void
 */
void bling(char **av, char **env)
{
	char *str = NULL;
	int i,status;
	size_t n = 0;
	ssize_t num_ch;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		num_ch = getline(&str, &n, stdin);
		if (num_ch == -1)
		{       free(str);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}
		argv[0] = str;
		child_pid = fork();

		if (child_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
