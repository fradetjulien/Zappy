/*
** EPITECH PROJECT, 2018
** ring_buffer
** File description:
** ring_buffer
*/

#ifndef RING_BUFFER_
#define RING_BUFFER_

typedef struct ring_buffer {
	char buffer[4096];
	char *read_rb;
	char *write_rb;
}rbuffer;

rbuffer *ring_buffer_init();
void free_ring_buffer(rbuffer *buffer);
void write_ring_buffer(rbuffer *buffer, char *str);
char *read_ring_buffer(rbuffer *buffer);
int ring_buffer_avaible(rbuffer *buffer);

#endif
