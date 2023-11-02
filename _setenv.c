#include "main.h"
#include <stdlib.h>

/**
 * _setenv - set environment variables
 * @shell_data: shell data
 * Return: void
*/
void _setenv(info_t *shell_data)
{
	char *token;
	char *string_copy = _strdup(shell_data->line);

	token = _strtok(string_copy, " ");
	token = _strtok(NULL, " ");
	if (token == NULL)
	{
		free_multiple(1, string_copy);
		return;
	}
}
