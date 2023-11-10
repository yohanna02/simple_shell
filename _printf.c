#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _dprintf - Custom dprintf function
 * @fd: File descriptor
 * @format: string format
 * Return: number of printed characters
 */
int _dprintf(int fd, const char *format, ...)
{
	va_list arg_list;
	int i = 0, j = 0, count = 0, buffer_index = 0;
	int (*f)(int, va_list, char *, int *);
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			f = select_specifier(format[i + 1]);
			if (f != NULL)
			{
				j = f(fd, arg_list, buffer, &buffer_index);
				if (j == -1)
					return (-1);
				count += j;
			}
			if (f == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					count += add_to_buffer(fd, buffer, &buffer_index, format[i]);
					count += add_to_buffer(fd, buffer, &buffer_index, format[i + 1]);
				}
				else
					return (-1);
			}
			i++;
		}
		else
			count += add_to_buffer(fd, buffer, &buffer_index, format[i]);
		i++;
	}
	flush_buffer(fd, buffer, &buffer_index);
	va_end(arg_list);
	return (count);
}
