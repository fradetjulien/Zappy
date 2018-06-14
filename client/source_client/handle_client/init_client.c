/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init_client.c
*/

#include "client.h"

t_socket	*init_client(t_client *client)
{
	client->socket = malloc(sizeof(t_socket));
	if (client->socket == NULL) {
		return (NULL);
	}
	client->socket->fd = -1;
	client->abscissa = 0;
	client->orderly = 0;
	client->team = NULL;
	client->port = NULL;
	client->read = NULL;
	client->host = LOCALHOST;
	return (client->socket);
}
