#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * select_specifier - select the specified function
 * @specifier: the function to select
 * Return: pointer to the selected function
 */
int (*select_specifier(char specifier))(int, va_list, char *, int *)
{
	int i = 0;
	specifier_t _specifier[] = {
		{'s', print_string},
		{'c', print_char},
		{'i', print_number},
		{'d', print_number},
		{'\0', NULL}
	};

	while (1)
	{
		if (_specifier[i].specifier == '\0')
		{
			break;
		}
		if (_specifier[i].specifier != specifier)
		{
			i++;
			continue;
		}

		return (_specifier[i].f);
	}

	return (NULL);
}
