#include "main.h"
#include <stdarg.h>

/**
 * print_char - print a character
 * @fd: File descriptor
 * @arg_list: arguments
 * @buffer: the buffer to add the string to
 * @buffer_index: the index of the string
 * Return: number of characters printed
 */
int print_char(int fd, va_list arg_list, char *buffer, int *buffer_index)
{
	int i;
	char c = va_arg(arg_list, int);

	i = add_to_buffer(fd, buffer, buffer_index, c);
	return (i);
}
