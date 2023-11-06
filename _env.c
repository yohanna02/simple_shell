#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * init_env - Setup environment variable
 * @shell_data: The shell data
 * Return: void
*/
void init_env(info_t *shell_data)
{

}

/**
 * _getenv - get an environmental variable
 * @variable: variable to find
 * Return: variable if found, else NULL
*/
char *_getenv(char *variable)
{
	int i = 0;
	size_t len = _strlen(variable);

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], variable, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}

/**
 * _setenv - set environment variables
 * @name: name of variable
 * @value: value of the variable
 * @overwrite: 1 to update if it exist, 0 to ignore
 * Return: 0 if success, -1 error
*/
int _setenv(char *name, char *value, int overwrite)
{
	char *env_var;
	char *new_env_var;
	int i = 0, len = 0;

	if (name == NULL || value == NULL)
		return (-1);
	env_var = _getenv(name);
	if (env_var != NULL && overwrite == 0)
		return (-1);
	new_env_var = _malloc(_strlen(name) + _strlen(value) + 2);
	_strcpy(new_env_var, name);
	_strcat(new_env_var, "=");
	_strcat(new_env_var, value);
	len = _strlen(name);
	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, len) == 0)
		{
			if (overwrite == 0)
			{
				free_multiple(1, new_env_var);
				return (0);
			}
			else
			{
				environ[i] = new_env_var;
				return (0);
			}
		}
		i++;
	}
	environ[i] = new_env_var;
	environ[i + 1] = NULL;
	return (0);
}
