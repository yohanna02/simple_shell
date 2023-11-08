#include "main.h"
#include <stdio.h>

/**
 * main - Entry point for shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, -1 on failure
*/
int main(__attribute__((unused)) int ac, char **av)
{
	ssize_t read;
	size_t len = 0;
	info_t shell_data = {
		NULL, 1, "\0", 0, 0
	};

	init_env(&shell_data);
	_strcpy(shell_data.shell_name, av[0]);
	if (!isatty(STDIN_FILENO))
		shell_data.interactive = 0;
	prompt(&shell_data);
	while ((read = _getline(&shell_data.line, &len, stdin)) != -1)
	{
		if (shell_data.line[0] == '\n')
		{
			prompt(&shell_data);
			continue;
		}
		if (shell_data.line[read - 1] == '\n')
			shell_data.line[read - 1] = '\0';

		run_cmd(&shell_data);
		prompt(&shell_data);
	}
	free_multiple(1, shell_data.line);
	return (0);
}
