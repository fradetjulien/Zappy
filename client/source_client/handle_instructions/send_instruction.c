/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** send_instruction.c
*/

#include "client.h"

int		send_instruction(t_client *client, char *instruction)
{
	dprintf(client->socket->fd, "%s\n", instruction);
	return (0);
}
