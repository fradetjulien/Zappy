/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** launch_client.c
*/

#include "client.h"

int			check_fds(t_client *client)
{
	if (FD_ISSET(0, client->read)) {
		if (read_instruction(client) == -1)
			return (-1);
	}
	if (FD_ISSET(client->socket->fd, client->read)) {
		
	}
	return (0);
}

void			init_fds(t_client *client, struct timeval *time)
{
	if (client->read != NULL) {
		FD_ZERO(client->read);
	}
	FD_SET(0, client->read);
	FD_SET(client->socket->fd, client->read);
	time->tv_sec = 0;
	time->tv_usec = 50;
}

int			launch_client(t_client *client)
{
	int		fdMax = client->socket->fd + 1;
	int		launcher = 1;
	struct timeval	time;

	while (launcher) {
		init_fds(client, &time);
		if (select(fdMax, client->read, NULL, NULL, &time) == -1) {
			printf("Select error\n");
			return (-1);
		}
		if (check_fds(client) == -1) {
			return (-1);
		}
	}
	return (0);
}
