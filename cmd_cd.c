#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * cd_only - Handles cd only command
 * @shell_data: Shell Data
 * Return: void
*/
void cd_only(info_t *shell_data)
{
	char *home_dir = _getenv("HOME");

	if (home_dir == NULL)
	{
		dprintf(STDERR_FILENO, "%s: cd: HOME not set\n",
		shell_data->shell_name);
		return;
	}
	if (_cd(home_dir) == -1)
	{
		dprintf(STDERR_FILENO, "%s: cd: Failed\n",
		shell_data->shell_name);
	}
}

/**
 * cd_old_dir - Handles going to old directory
 * @shell_data: Shell Data
 * Return: void
*/
void cd_old_dir(info_t *shell_data)
{
	char *old_dir = _getenv("OLDPWD");

	if (old_dir == NULL)
	{
		dprintf(STDERR_FILENO, "%s: cd: OLDPWD not set\n",
		shell_data->shell_name);
		return;
	}
	if (_cd(old_dir) == -1)
	{
		dprintf(STDERR_FILENO, "%s: cd: Failed\n",
		shell_data->shell_name);
		return;
	}
	dprintf(STDOUT_FILENO, "%s\n", old_dir);
}

/**
 * cmd_cd - Handles the cd command
 * @shell_data: Shell Data
 * Return: void
*/
void cmd_cd(info_t *shell_data)
{
	char *command, *path;
	struct stat sb;

	command = _strdup(shell_data->line);
	_strtok(command, " ");
	path = _strtok(NULL, " ");
	if (path == NULL)
		cd_only(shell_data);
	else if (_strncmp(path, "-", 1) == 0)
		cd_old_dir(shell_data);
	else
	{
		if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
		{
			if (!(sb.st_mode & S_IRUSR) ||
				!(sb.st_mode & S_IWUSR) ||
				!(sb.st_mode & S_IXUSR))
			{
				dprintf(STDERR_FILENO, "%s: cd: %s: Permission denied\n",
				shell_data->shell_name, path);
			}
			else
			{
				if (_cd(path) == -1)
				{
					dprintf(STDERR_FILENO, "%s: cd: Failed\n",
					shell_data->shell_name);
					free_multiple(1, command);
					return;
				}
			}
		}
		else
		{
			dprintf(STDERR_FILENO, "%s: cd: %s: No such file or directory\n",
			shell_data->shell_name, path);
		}
	}
	free_multiple(1, command);
}
