#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _puts - prints a string
 * @fd: File descriptor
 * @str: string to print
 * @buffer: the buffer to add the string to
 * @buffer_index: the index of the string
 * Return: number of printed characters
 */
int _puts(int fd, char *str, char *buffer, int *buffer_index)
{
	int count = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		count += add_to_buffer(fd, buffer, buffer_index, str[i]);
	}
	return (count);
}

/**
 * print_string - prints string
 * @fd: File descriptor
 * @arg_list: string to print
 * @buffer: the buffer to add the string to
 * @buffer_index: the index of the string
 * Return: number of printed characters
*/
int print_string(int fd, va_list arg_list, char *buffer, int *buffer_index)
{
	int i = 0, count = 0;
	char *str = va_arg(arg_list, char *);

	if (str == NULL)
	{
		count = _puts(fd, "(null)", buffer, buffer_index);
		return (count);
	}
	while (str[i])
	{
		count += add_to_buffer(fd, buffer, buffer_index, str[i]);
		i++;
	}
	return (count);
}
