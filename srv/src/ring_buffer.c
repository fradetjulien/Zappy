/*
** EPITECH PROJECT, 2018
** ring_buffer
** File description:
** ring_buffer
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ring_buffer.h"

rbuffer *ring_buffer_init()
{
	rbuffer *buffer = malloc(sizeof(rbuffer));

	memset(buffer, 0, 4096);
	buffer->read_rb = buffer->buffer;
	buffer->write_rb = buffer->buffer;
	return (buffer);
}

void free_ring_buffer(rbuffer *buffer)
{
	if (buffer)
		free(buffer);
}

void write_ring_buffer(rbuffer *buffer, char *str)
{
	if (!buffer->write_rb)
		buffer->write_rb = buffer->read_rb;
	for (int i = 0; str[i]; ++i) {
		*buffer->write_rb = str[i];
		buffer->write_rb = &buffer->buffer[(((size_t)buffer->write_rb + 1)
			     - (size_t)buffer->buffer) % 4096];
	}
}

char *read_ring_buffer(rbuffer *buffer)
{
	char *str;
	size_t size = 0;

	if (buffer->write_rb >= buffer->read_rb)
		size = (size_t)(buffer->write_rb - buffer->read_rb);
	else
		size = 4096 - ((size_t)(buffer->read_rb - buffer->write_rb));
	str = malloc(sizeof(char) * size + 1);
	memset(str, 0, size + 1);
	for (size_t i = 0; i < size; ++i) {
		str[i] = *buffer->read_rb;
		buffer->read_rb = &buffer->buffer[(((size_t)buffer->read_rb + 1)
			     - (size_t)buffer->buffer) % 4096];
	}
	return (str);
}

int ring_buffer_avaible(rbuffer *buffer)
{
	int a = 0;

	if (buffer->write_rb >= buffer->read_rb)
		a = 4096 - (int)(buffer->write_rb - buffer->read_rb);
	else
		a = (int)(buffer->read_rb - buffer->write_rb);
	return (a);
}
