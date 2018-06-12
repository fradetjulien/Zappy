/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** connection_serveur.c
*/

#include "client.h"

int		connection_server(t_client *client)
{
	int	error = 0;

	if (init_socket(client, "TCP") == -1) {
		printf("Can not initialize connection\n");
		return (-1);
	}
	client->socket->s.sin_family = AF_INET;
	client->socket->s.sin_addr.s_addr = inet_addr(client->host);
	client->socket->s.sin_port = htons(atoi(client->port));
	error = connect(client->socket->fd, (const struct sockaddr *)&client->socket->s,
			sizeof(client->socket->s));
	if (error == -1) {
		printf("Can not establish connection\n");
		close_socket(client);
		return (-1);
	}
	return (0);
}
