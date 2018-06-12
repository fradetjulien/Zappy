/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** close_socket.c
*/

#include "client.h"

int		close_socket(t_client *client)
{
	if (close(client->socket->fd) == -1) {
		return (-1);
	}
	client->socket->fd = -1;
	return (0);
}
