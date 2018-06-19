/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** contact_server.c
*/

#include "client.h"

int		contact_server(t_client *client, char *instructReceived)
{
	int	error = 0;

	error = send_instruction(client, client->team);
	if (error == -1) {
		return (-1);
	}
	instructReceived = print_instruction(instructReceived, 1);
	instructReceived = print_instruction(client->team, 0);
	if (instructReceived == NULL) {
		return (-1);
	}
	return (0);
}
