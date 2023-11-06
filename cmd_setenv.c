#include "main.h"

/**
 * cmd_setenv - exit from shell
 * @shell_data: shell data
 * Return: void
*/
void cmd_setenv(info_t *shell_data)
{
	char *name, *value;
	char *string_copy = _strdup(shell_data->line);

	_strtok(string_copy, " ");
	name = _strtok(NULL, " ");
	value = _strtok(NULL, " ");
	if (_setenv(name, value, 1) == -1)
	{
		dprintf(STDERR_FILENO, "%s: 1: setenv: Illegal argument\n",
		shell_data->shell_name);
	}
	free_multiple(1, string_copy);
}
