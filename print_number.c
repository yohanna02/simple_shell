#include "main.h"
#include <stdarg.h>

/**
 * print_integer - prints an integer
 * @fd: File descriptor
 * @n: integer to be printed
 * @buffer: the buffer to add the string to
 * @buffer_index: the index of the string
 * Return: number of characters printed
 */
int print_integer(int fd, int n, char *buffer, int *buffer_index)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += add_to_buffer(fd, buffer, buffer_index, '-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_integer(fd, num / 10, buffer, buffer_index);
	}

	count += add_to_buffer(fd, buffer, buffer_index, (num % 10) + '0');
	return (count);
}

/**
 * print_number - prints an integer
 * @fd: File descriptor
 * @arg_list: integer to be printed
 * @buffer: the buffer to add the string to
 * @buffer_index: the index of the string
 * Return: number of characters printed
 */
int print_number(int fd, va_list arg_list, char *buffer, int *buffer_index)
{
	int count = 0, n;

	n = va_arg(arg_list, int);

	count = print_integer(fd, n, buffer, buffer_index);

	return (count);
}
