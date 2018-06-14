/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** launch_client.c
*/

#include "client.h"

int			check_fds(t_client *client)
{
	static int	is_AlreadySend = 0;
	char		*instructReceived = NULL;
	int		error = 0;

	if (FD_ISSET(client->socket->fd, &client->read)) {
		instructReceived = get_instruction(client);
		if (is_AlreadySend == 2) {
			if (world_dimension(client, instructReceived) == 0)
				is_AlreadySend = 3;
		}
		if (is_AlreadySend == 1) {
			if (remaining_places(instructReceived) == 0)
				is_AlreadySend = 2;
		}
		if (is_AlreadySend == 0 && is_welcome(instructReceived) == 0) {
			if (contact_server(client, instructReceived) == 0)
				is_AlreadySend = 1;
		}
		free(instructReceived);
		instructReceived = NULL;
	}
	return (error);
}

void			init_fds(int fd, fd_set *read, struct timeval *time)
{
	FD_ZERO(read);
	FD_SET(fd, read);
	FD_SET(0, read);
	time->tv_sec = 0;
	time->tv_usec = 50;
}

int			launch_client(t_client *client)
{
	int		fdMax = client->socket->fd + 1;
	int		launcher = 1;
	struct timeval	time;

	while (launcher) {
		init_fds(client->socket->fd, &client->read, &time);
		if (select(fdMax, &client->read, NULL, NULL, &time) == -1) {
			printf("Select error\n");
			return (-1);
		}
		if (check_fds(client) == -1)
			return (-1);
	}
	return (0);
}
