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

	client.socket = init_client(&client);
	if (ac != 7 || isWriteArguments(av) != 0) {
		help_client(av[0]);
		return (-1);
	}
	free_client(client);
	return (0);
}
