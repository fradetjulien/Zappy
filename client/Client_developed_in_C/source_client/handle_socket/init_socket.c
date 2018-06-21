/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init_socket.c
*/

#include "client.h"

int		init_socket(t_client *client, const char *protocol)
{
	client->protocol = getprotobyname(protocol);
	if (client->protocol == NULL) {
		return (-1);
	}
	client->socket->fd = socket(AF_INET, SOCK_STREAM,
	client->protocol->p_proto);
	if (client->socket->fd == -1) {
		return (-1);
	}
	return (0);
}
