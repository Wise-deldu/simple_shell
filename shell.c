#include "shell.h"

/**
 * main - Entry to the program
 * @ac: integer to represent the number of arguments passed.
 * @av: array of strings containing command-line arguments
 * @env: array of strings representing environment variables.
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
