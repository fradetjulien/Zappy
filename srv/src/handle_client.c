/*
** EPITECH PROJECT, 2018
** handle_client
** File description:
** handle_client
*/

#include "server.h"
#include "ring_buffer.h"

int first_cmd(char *buffer, int fd, server *server)
{
	if (strcmp(buffer, "ah\n") == 0) {
		dprintf(fd, "%d %d\n", server->width, server->height);
	}
	return (0);
}

int	read_cmd(char *buffer, int fd)
{
	int r = read(fd, buffer, 4096);

	if (r == -1)
		return -1;
	else if (r == 0) {
		printf("Client disconnected : %d\n", fd);
		close(fd);
	}
	buffer[r] = '\0';
	return (0);
}

int	manage_cmd(server *server, int fd)
{
	char buffer[4096];
	
	if (read_cmd(buffer, fd) == -1)
		return -1;
	first_cmd(buffer, fd, server);
	return 0;
}
