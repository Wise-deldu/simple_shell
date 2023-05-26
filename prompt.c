#include "shell.h"
#include <sys/wait.h>

#define MAX_COMMAND 20

/**
 * prompt - This function prompts for an input, execute commands,
 * wait for a child process until an error occurs before it
 * terminates or terminated externally.
 *
 * @av: to represent command-line arguments passed to the program.
 * @env: represents the environment variables available to the program.
 */

void prompt(char **av, char **env)
{
	char *string = NULL;
	int j, k, status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[MAX_COMMAND];
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (string[j])
		{
			if (string[j] == '\n')
				string[j] = 0;
			j++;
		}

		k = 0;
		argv[k] = strtok(string, " ");
		while (argv [k])
		{
			k++;
			argv[k] = strtok(NULL, " ");
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file on directory\n", av[0]);
		}
		else
			wait(&status);
	}
}

