/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** is_writearguments.c
*/

#include "client.h"

int		is_writearguments(t_client *client, char **av)
{
	if ((strcmp(av[0], "./zappy_ai") != 0) ||
	(strcmp(av[1], "-p") != 0) ||
	(strcmp(av[3], "-n") != 0) ||
	(strcmp(av[5], "-h") != 0)) {
		return (-1);
	}
	else if (is_hostname(av[6]) != 0 || is_port(av[2]) != 0) {
		return (-1);
	}
	else {
		client->port = strdup(av[2]);
		client->team = strdup(av[4]);
		client->host = strdup(av[6]);
	}
	return (0);
}
