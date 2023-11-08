#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * _cd - recreate cd function
 *
 * @path: path
 * Return: env change
 */

int _cd(const char *path)
{
	char *old_pwd = NULL;
	char *new_pwd = NULL;

	old_pwd = getcwd(NULL, 0);

	if (old_pwd == NULL)
	{
		/* perror("getcwd"); */
		return (-1);
	}

	if (chdir(path) != 0)
	{
		/* perror("chdir"); */
		free(old_pwd);
		return (-1);
	}

	new_pwd = getcwd(NULL, 0);

	if (new_pwd == NULL)
	{
		/* perror("getcwd"); */
		free(old_pwd);
		return (-1);
	}

	setenv("PWD", new_pwd, 1);
	setenv("OLDPWD", old_pwd, 1);

	free(old_pwd);
	free(new_pwd);

	return (0);
}

