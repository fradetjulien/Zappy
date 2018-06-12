/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** send_instruction.c
*/

#include "client.h"

int		send_instruction(t_client  *client, char *instruction)
{
	int	error = 0;

	error = write(client->socket->fd, instruction, strlen(instruction));
	if (error == -1) {
		return (-1);
	}
	return (0);
}
