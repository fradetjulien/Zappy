/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** isWriteArguments.c
*/

#include "client.h"

int		isWriteArguments(t_client *client, char **av)
{
	if ((strcmp(av[0], "./zappy_ai") != 0) ||
	    (strcmp(av[1], "-p") != 0) ||
	    (strcmp(av[3], "-n") != 0) ||
	    (strcmp(av[5], "-h") != 0)) {
		return (-1);
	}
	else if (isHostname(av[6]) != 0 || isPort(av[2]) != 0) {
		return (-1);
	}
	else {
		client->port = strdup(av[2]);
		client->team = strdup(av[4]);
		client->host = strdup(av[6]);
	}
	return (0);
}
