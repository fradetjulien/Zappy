/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client.c
*/

#include "client.h"

int			main(int ac, char **av)
{
	t_client	client;
	int		error = 0;

	client.socket = init_client(&client);
	if (ac != 7 || isWriteArguments(&client, av) != 0) {
		help_client(av[0]);
		return (-1);
	}
	if (connection_serveur(&client) == -1) {
		return (-1);
	}
	if (launch_client(&client) == -1) {
		return (-1);
	}
	free_client(client);
	return (0);
}
