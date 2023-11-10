#include "main.h"
#include <unistd.h>

/**
 * add_to_buffer - add a string to the buffer
 * @fd: File descriptor
 * @buffer: the buffer to add the string to
 * @buffer_index: the index of the string
 * @c: the character to append to the buffer
 * Return: number of characters added to the buffer
 */
int add_to_buffer(int fd, char *buffer, int *buffer_index, char c)
{
	if (*buffer_index == BUFFER_SIZE)
	{
		flush_buffer(fd, buffer, buffer_index);
	}
	buffer[(*buffer_index)] = c;
	(*buffer_index)++;

	return (1);
}

/**
 * flush_buffer - print the buffer to stdout
 * @fd: File descriptor
 * @buffer: the buffer to add the string to
 * @buffer_index: the index of the string
 * Return: void
 */
void flush_buffer(int fd, char *buffer, int *buffer_index)
{
	write(fd, buffer, *buffer_index);
	*buffer_index = 0;
}
